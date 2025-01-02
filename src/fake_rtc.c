#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

static void Script_PauseFakeRtc(void);
static void Script_ResumeFakeRtc(void);
static void FakeRtc_CalcTimeDifference(struct Time *result, struct SiiRtcInfo *t1, struct Time *t2);

void FakeRtc_Reset(void)
{
#if OW_USE_FAKE_RTC
    memset(&gSaveBlock3Ptr->fakeRTC, 0, sizeof(gSaveBlock3Ptr->fakeRTC));
    gSaveBlock3Ptr->fakeRTC.month = MONTH_JAN;
    gSaveBlock3Ptr->fakeRTC.day = 1;
    gSaveBlock3Ptr->fakeRTC.dayOfWeek = WEEKDAY_SAT;
#endif
}

struct SiiRtcInfo *FakeRtc_GetCurrentTime(void)
{
#if OW_USE_FAKE_RTC
    return &gSaveBlock3Ptr->fakeRTC;
#else
    return NULL;
#endif
}

void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc)
{
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();
    if (fakeRtc != NULL)
        memcpy(rtc, fakeRtc, sizeof(struct SiiRtcInfo));
}

void FakeRtc_TickTimeForward(void)
{
    if (!OW_USE_FAKE_RTC)
        return;

    if (FlagGet(OW_FLAG_PAUSE_TIME))
        return;

    FakeRtc_AdvanceTimeBy(0, 0, 0, FakeRtc_GetSecondsRatio());
}

static void FakeRtc_AdvanceSeconds(struct SiiRtcInfo *rtc, u32 *days, u32 *hours, u32 *minutes, u32 *seconds)
{
    *seconds += rtc->second;
    *minutes += rtc->minute;
    *hours += rtc->hour;

    while (*seconds >= SECONDS_PER_MINUTE)
    {
        (*minutes)++;
        *seconds -= SECONDS_PER_MINUTE;
    }
    while (*minutes >= MINUTES_PER_HOUR)
    {
        (*hours)++;
        *minutes -= MINUTES_PER_HOUR;
    }
    while (*hours >= HOURS_PER_DAY)
    {
        (*days)++;
        *hours -= HOURS_PER_DAY;
    }
    
    rtc->second = *seconds;
    rtc->minute = *minutes;
    rtc->hour = *hours;
}

static void FakeRtc_SetDayOfWeek(struct SiiRtcInfo *rtc, u32 daysToAdd)
{
    rtc->dayOfWeek = (rtc->dayOfWeek + daysToAdd) % WEEKDAY_COUNT;
}

static void FakeRtc_AdvanceDays(struct SiiRtcInfo *rtc, u32 *days)
{
    Script_PauseFakeRtc();
    u32 remainingDaysInMonth = (sNumDaysInMonths[rtc->month - 1] + (rtc->month == MONTH_FEB && IsLeapYear(rtc->year)) - rtc->day);
    if (*days > remainingDaysInMonth)
    {
        rtc->day = 1;
        rtc->month++;
        if (rtc->month > MONTH_DEC)
        {
            rtc->month = MONTH_JAN;
            rtc->year++;
        }
        *days -= (remainingDaysInMonth + 1);
        FakeRtc_SetDayOfWeek(rtc, remainingDaysInMonth + 1);
    }
    else
    {
        rtc->day += *days;
        FakeRtc_SetDayOfWeek(rtc, *days);
        *days = 0;
    }
    Script_ResumeFakeRtc();
}

void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds)
{
    Script_PauseFakeRtc();
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    FakeRtc_AdvanceSeconds(rtc, &days, &hours, &minutes, &seconds);

    while (days > 0)
        FakeRtc_AdvanceDays(rtc, &days);
    Script_ResumeFakeRtc();
}

void FakeRtc_ForwardTimeTo(u32 hour, u32 minute, u32 second)
{
    Script_PauseFakeRtc();
    struct Time diff, target;
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();

    target.hours = hour;
    target.minutes = minute;
    target.seconds = second;

    FakeRtc_CalcTimeDifference(&diff, fakeRtc, &target);

    FakeRtc_AdvanceTimeBy(0, diff.hours, diff.minutes, diff.seconds);

    Script_ResumeFakeRtc();
}


static void FakeRtc_CalcTimeDifference(struct Time *result, struct SiiRtcInfo *t1, struct Time *t2)
{
    result->seconds = t2->seconds - t1->second;
    result->minutes = t2->minutes - t1->minute;
    result->hours = t2->hours - t1->hour;
    result->days = t2->days - t1->day;

    if (result->seconds < 0)
    {
        result->seconds += SECONDS_PER_MINUTE;
        --result->minutes;
    }

    if (result->minutes < 0)
    {
        result->minutes += MINUTES_PER_HOUR;
        --result->hours;
    }

    if (result->hours < 0)
    {
        result->hours += HOURS_PER_DAY;
        --result->days;
    }
}

void FakeRtc_ForceSetTime(u32 day, u32 hour, u32 minute, u32 second)
{
    FakeRtc_Reset();
    FakeRtc_AdvanceTimeBy(day, hour, minute, second);
}

u32 FakeRtc_GetSecondsRatio(void)
{
    return (OW_ALTERED_TIME_RATIO == GEN_8_PLA) ? 60 :
           (OW_ALTERED_TIME_RATIO == GEN_9)     ? 20 :
           (OW_ALTERED_TIME_RATIO == RTC_CUSTOM)? 12 :
                                                  1;
}

STATIC_ASSERT((OW_FLAG_PAUSE_TIME == 0 || OW_USE_FAKE_RTC == TRUE), FakeRtcMustBeTrueToPauseTime);

void Script_PauseFakeRtc(void)
{
    FlagSet(OW_FLAG_PAUSE_TIME);
}

void Script_ResumeFakeRtc(void)
{
    FlagClear(OW_FLAG_PAUSE_TIME);
}

void Script_ToggleFakeRtc(void)
{
    FlagToggle(OW_FLAG_PAUSE_TIME);
}

/////////////////////////////
//////// TIME MACROS ////////
/////////////////////////////

bool8 ScrCmd_addtime(struct ScriptContext *ctx)
{
    u32 addedDays = ScriptReadWord(ctx);
    u32 addedHours = ScriptReadWord(ctx);
    u32 addedMinutes = ScriptReadWord(ctx);
    FakeRtc_AdvanceTimeBy(addedDays, addedHours, addedMinutes, 0);
    return FALSE;
}

bool8 ScrCmd_forwardtime(struct ScriptContext *ctx)
{
    u32 setHour = ScriptReadWord(ctx);
    u32 setMinute = ScriptReadWord(ctx);
    FakeRtc_ForwardTimeTo(setHour, setMinute, 0);
    return FALSE;
}

bool8 ScrCmd_setdayofweek(struct ScriptContext *ctx)
{
    
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    
    u32 weekdayTarget = ScriptReadWord(ctx);
    u32 weekdayCurrent = rtc->dayOfWeek;
    u32 daysToAdd;

    daysToAdd = ((weekdayTarget - weekdayCurrent) + 7) % 7;

    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0);
    return FALSE;
}

///////////////////////////////////
//////// TESTING FUNCTIONS ////////
///////////////////////////////////

/*
void Script_Testing1(void)
{
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();
    MgbaPrintf(MGBA_LOG_WARN, "Days Before AdvanceTime runs: %u", fakeRtc->day);
    MgbaPrintf(MGBA_LOG_WARN, "Day of the week Before AdvanceTime runs: %u", fakeRtc->dayOfWeek);
    MgbaPrintf(MGBA_LOG_WARN, "Hours Before AdvanceTime runs: %u", fakeRtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "Minutes Before AdvanceTime runs: %u", fakeRtc->minute);
    FakeRtc_AdvanceTimeBy(1, 6, 6, 0);
    MgbaPrintf(MGBA_LOG_WARN, "Days After AdvanceTime runs: %u", fakeRtc->day);
    MgbaPrintf(MGBA_LOG_WARN, "Day of the week After AdvanceTime runs: %u", fakeRtc->dayOfWeek);
    MgbaPrintf(MGBA_LOG_WARN, "Hours After AdvanceTime runs: %u", fakeRtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "Minutes After AdvanceTime runs: %u", fakeRtc->minute);
}

void Script_Testing2(void)
{
    MgbaPrintf(MGBA_LOG_WARN, "Hour: %u", rtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "Minute: %u", rtc->minute);
    FakeRtc_ForwardTimeTo(20, 12, 0);
    MgbaPrintf(MGBA_LOG_WARN, "Hour: %u", rtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "Minute: %u", rtc->minute);
}

void Script_Testing3(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    
    u32 weekdayTarget = 5;
    u32 weekdayCurrent = rtc->dayOfWeek;
    u32 daysToAdd;

    daysToAdd = ((weekdayTarget - weekdayCurrent) + 7) % 7;

    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0);
}
*/