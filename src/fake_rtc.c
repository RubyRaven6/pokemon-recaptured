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
#if OW_USE_FAKE_RTC
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

    FakeRtc_AdvanceTimeBy(0, 0, 0, FakeRtc_GetSecondsRatio());
}

void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds)
{
    struct Time* time = FakeRtc_GetCurrentTime();
    seconds += time->seconds;
    minutes += time->minutes;
    hours += time->hours;
    days += time->days;

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
    time->days = days;
}

void FakeRtc_ManuallySetTime(u32 dayOfWeek, u32 hour, u32 minute, u32 second)
{
    u8 weekday = ((day - 1) % 7);

    memset(FakeRtc_GetCurrentTime(), 0, sizeof(struct Time));
    struct Time* initTime = FakeRtc_GetCurrentTime();

    initTime->years = year;
    initTime->months = month;
    initTime->days = day; 
    initTime->dayOfWeek = weekday;
    initTime->hours = hour;
    initTime->minutes = minute;
    initTime->seconds = second;
    return;
}

void SetNewIngameTime(void)
{
    u32 Year = STARTING_YEAR;
    u32 Month = STARTING_MONTH;
    u32 Day = STARTING_DAY;
    u32 Hour = STARTING_HOUR;
    u32 Minute = STARTING_MINUTE;
    u32 Second = STARTING_SECOND;
    FakeRtc_ManuallySetTime(Year, Month, Day, Hour, Minute, Second);
}

// Edit the value after ? of RTC_CUSTOM to edit the custom ratio. 
u32 FakeRtc_GetSecondsRatio(void)
{
    return (OW_ALTERED_TIME_RATIO == GEN_8_PLA)   ? 60 :
           (OW_ALTERED_TIME_RATIO == GEN_9)       ? 20 :
           (OW_ALTERED_TIME_RATIO == RTC_CUSTOM)  ?  1 :
                                                     1 ;
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

//These are the scripts which control the time macros in event.inc

bool8 RtcCmd_addtime(struct ScriptContext *ctx)
{
    u32 years = ScriptReadWord(ctx);
    u32 months = ScriptReadWord(ctx);
    u32 days = ScriptReadWord(ctx);
    u32 hours = ScriptReadWord(ctx);
    u32 minutes = ScriptReadWord(ctx);
    u32 seconds = ScriptReadWord(ctx);
   
    FakeRtc_AdvanceTimeBy(years, months, days, hours, minutes, seconds);

    return FALSE;
    
}

bool8 RtcCmd_settime(struct ScriptContext *ctx)
{
    u32 year = ScriptReadWord(ctx);
    u32 month = ScriptReadWord(ctx);
    u32 day = ScriptReadWord(ctx);
    u32 hour = ScriptReadWord(ctx);
    u32 minute = ScriptReadWord(ctx);
    u32 second = ScriptReadWord(ctx);

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_addyear(struct ScriptContext *ctx)
{
    u32 year = ScriptReadWord(ctx);
    u32 month = 0;
    u32 day = 0;
    u32 hour = 0;
    u32 minute = 0;
    u32 second = 0;

    FakeRtc_AdvanceTimeBy(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_addmonth(struct ScriptContext *ctx)
{
    u32 year = 0;
    u32 month = ScriptReadWord(ctx);
    u32 day = 0;
    u32 hour = 0;
    u32 minute = 0;
    u32 second = 0;

    FakeRtc_AdvanceTimeBy(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_addday(struct ScriptContext *ctx)
{
    u32 year = 0;
    u32 month = 0;
    u32 day = ScriptReadWord(ctx);
    u32 hour = 0;
    u32 minute = 0;
    u32 second = 0;

    FakeRtc_AdvanceTimeBy(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_addhour(struct ScriptContext *ctx)
{
    u32 year = 0;
    u32 month = 0;
    u32 day = 0;
    u32 hour = ScriptReadWord(ctx);
    u32 minute = 0;
    u32 second = 0;

    FakeRtc_AdvanceTimeBy(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_addminute(struct ScriptContext *ctx)
{
    u32 year = 0;
    u32 month = 0;
    u32 day = 0;
    u32 hour = 0;
    u32 minute = ScriptReadWord(ctx);
    u32 second = 0;

    FakeRtc_AdvanceTimeBy(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_setyear(struct ScriptContext *ctx)
{
    struct Time *time = FakeRtc_GetCurrentTime();
    
    u32 year = ScriptReadWord(ctx);
    u32 month = time->months;
    u32 day = time->days;
    u32 hour = time->hours;
    u32 minute = time->minutes;
    u32 second = time->seconds;

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_setmonth(struct ScriptContext *ctx)
{
    struct Time *time = FakeRtc_GetCurrentTime();
    
    u32 year = time->years;
    u32 month = ScriptReadWord(ctx);
    u32 day = time->days;
    u32 hour = time->hours;
    u32 minute = time->minutes;
    u32 second = time->seconds;

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_setday(struct ScriptContext *ctx)
{
    struct Time *time = FakeRtc_GetCurrentTime();
    
    u32 year = time->years;
    u32 month = time->months;
    u32 day = ScriptReadWord(ctx);
    u32 hour = time->hours;
    u32 minute = time->minutes;
    u32 second = time->seconds;

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_sethour(struct ScriptContext *ctx)
{
    struct Time *time = FakeRtc_GetCurrentTime();
    
    u32 year = time->years;
    u32 month = time->months;
    u32 day = time->days;
    u32 hour = ScriptReadWord(ctx);
    u32 minute = time->minutes;
    u32 second = time->seconds;

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}

bool8 RtcCmd_setminute(struct ScriptContext *ctx)
{
    struct Time *time = FakeRtc_GetCurrentTime();
    
    u32 year = time->years;
    u32 month = time->months;
    u32 day = time->days;
    u32 hour = time->hours;
    u32 minute = ScriptReadWord(ctx);
    u32 second = time->seconds;

    FakeRtc_ManuallySetTime(year, month, day, hour, minute, second);
    return FALSE;
}