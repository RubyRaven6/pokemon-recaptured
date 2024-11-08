#ifndef GUARD_FAKE_RTC_UTIL_H
#define GUARD_FAKE_RTC_UTIL_H

#include "siirtc.h"

struct Time* FakeRtc_GetCurrentTime(void);
void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc);
void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds);
void FakeRtc_ManuallySetTime(u32 day, u32 hour, u32 minute, u32 second);
void FakeRtc_TickTimeForward(void);
u32 FakeRtc_GetSecondsRatio(void);
void FakeRtc_CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2);
void Script_ToggleFakeRtc(void);

u8 GetYear(void);
u8 GetMonth(void);
u8 GetDay(void);
u8 GetHour(void);
u8 GetMinute(void);
u8 GetSecond(void);
u8 GetDayOfWeek(void);
void SetNewIngameTime(void);

#endif // GUARD_FAKE_RTC_UTIL_H
