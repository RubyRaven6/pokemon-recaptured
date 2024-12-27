#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

struct Time *FakeRtc_GetCurrentTime(void)
{
#if OW_USE_FAKE_RTC == TRUE
    return &gSaveBlock3Ptr->fakeRTC;
#else
    return NULL;
#endif
}

void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc)
{
    struct Time* time = FakeRtc_GetCurrentTime();
    rtc->second = time->seconds;
    rtc->minute = time->minutes;
    rtc->hour = time->hours;
    rtc->day = time->days;
}

void FakeRtc_TickTimeForward(void)
{
    if (!OW_USE_FAKE_RTC)
        return;

    if (FlagGet(OW_FLAG_PAUSE_TIME))
        return;

    FakeRtc_AdvanceTimeBy(0, 0, FakeRtc_GetSecondsRatio());
}

void FakeRtc_AdvanceTimeBy(u32 hours, u32 minutes, u32 seconds)
{
    struct Time* time = FakeRtc_GetCurrentTime();
    seconds += time->seconds;
    minutes += time->minutes;
    hours += time->hours;

    while(seconds >= SECONDS_PER_MINUTE)
    {
        minutes++;
        seconds -= SECONDS_PER_MINUTE;
    }

    while(minutes >= MINUTES_PER_HOUR)
    {
        hours++;
        minutes -= MINUTES_PER_HOUR;
    }

    while(hours >= HOURS_PER_DAY)
    {
        time->days++;
        hours -= HOURS_PER_DAY;
    }

    time->seconds = seconds;
    time->minutes = minutes;
    time->hours = hours;
}

void FakeRtc_ManuallySetTime(u32 hour, u32 minute, u32 second)
{
    Script_ToggleFakeRtc();

    struct Time diff, target;
    RtcCalcLocalTime();

    target.hours = hour;
    target.minutes = minute;
    target.seconds = second;

    CalcTimeDifference(&diff, &gLocalTime, &target);
    FakeRtc_AdvanceTimeBy(diff.hours, diff.minutes, diff.seconds);

    Script_ToggleFakeRtc();
}

void FakeRtc_ManuallySetDayOfWeek(u32 dayOfWeek){
    Script_ToggleFakeRtc();
    u32 localdaysMod = gLocalTime.days % 7;
    u32 dayOffset = (dayOfWeek - localdaysMod + 7) % 7;
    u32 dayAdvance = dayOffset * 24; // converts dayOffset to equivalent number of hours, to bring it to the specified day.
    FakeRtc_AdvanceTimeBy(dayAdvance, 0, 0);
    Script_ToggleFakeRtc();
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