#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

static void Script_ToggleFakeRtc(void);
static void FakeRtc_CalcTimeDifference(struct SiiRtcInfo *result, struct Time *t1, struct SiiRtcInfo *t2);

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
#if OW_USE_FAKE_RTC == TRUE
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

static void FakeRtc_AdvanceSeconds(struct SiiRtcInfo *rtc, u32 *days, u32*hours, u32 *minutes, u32 *seconds)
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
    Script_ToggleFakeRtc();
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
    Script_ToggleFakeRtc();
}

void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds)
{
    Script_ToggleFakeRtc();
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    FakeRtc_AdvanceSeconds(rtc, &days, &hours, &minutes, &seconds);

    while (days > 0)
        FakeRtc_AdvanceDays(rtc, &days);
    Script_ToggleFakeRtc();
}

void FakeRtc_ForwardTimeTo(u32 day, u32 hour, u32 minute, u32 second)
{
    Script_ToggleFakeRtc();
    struct SiiRtcInfo diff, target;
    RtcCalcLocalTime();

    target.hour = hour;
    target.minute = minute;
    target.second = second;
    target.day = day;

    FakeRtc_CalcTimeDifference(&diff, &gLocalTime, &target);
    FakeRtc_AdvanceTimeBy(diff.day, diff.hour, diff.minute, diff.second);
    Script_ToggleFakeRtc();
}

void FakeRtc_CalcTimeDifference(struct SiiRtcInfo *result, struct Time *t1, struct SiiRtcInfo *t2)
{
    result->second = t2->second - t1->seconds;
    result->minute = t2->minute - t1->minutes;
    result->hour = t2->hour - t1->hours;
    result->day = t2->day - t1->days;

    if (result->second < 0)
    {
        result->second += SECONDS_PER_MINUTE;
        --result->minute;
    }

    if (result->minute < 0)
    {
        result->minute += MINUTES_PER_HOUR;
        --result->hour;
    }

    if (result->hour < 0)
    {
        result->hour += HOURS_PER_DAY;
        --result->day;
    }
}

void FakeRtc_ForceSetTime(u32 day, u32 hour, u32 minute, u32 second)
{
    FakeRtc_Reset();
    FakeRtc_AdvanceTimeBy(day, hour, minute, second);
}

// void AdvanceScript(void)
// {
//     FakeRtc_AdvanceTimeBy(300, 0, 0, 0);
// }

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

static void Script_ToggleFakeRtc(void)
{
    FlagToggle(OW_FLAG_PAUSE_TIME);
}

bool8 ScrCmd_addtime(struct ScriptContext *ctx)
{
    u32 addedhours = ScriptReadWord(ctx);
    u32 addedminutes = ScriptReadWord(ctx);
    FakeRtc_AdvanceTimeBy(addedhours, addedminutes, 0);
    return FALSE;
}

bool8 ScrCmd_settime(struct ScriptContext *ctx)
{
    //u32 setDayOfWeek = ScriptReadWord(ctx);
    u32 setHour = ScriptReadWord(ctx);
    u32 setMinute = ScriptReadWord(ctx);
    FakeRtc_ManuallySetTime(setHour, setMinute, 0);
    return FALSE;
}

bool8 ScrCmd_setdayofweek(struct ScriptContext *ctx)
{
    u32 setDayOfWeek = ScriptReadWord(ctx);
    FakeRtc_ManuallySetDayOfWeek(setDayOfWeek);
    return FALSE;
}