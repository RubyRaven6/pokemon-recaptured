#include "global.h"
#include "fake_rtc.h"
#include "rtc.h"

enum WaitingMenu
{
    WAIT_MENU_WAIT_WHILE,
};

enum WaitingWhileMenu
{
    WAITWHILE_MENU_WAIT_3,
    WAITWHILE_MENU_WAIT_6,
    WAITWHILE_MENU_WAIT_9,
    WAITWHILE_MENU_WAIT_12,
};

static const u8 sWaitWhileText_Digit_3[]  =     _("Wait for 3 hours");
static const u8 sWaitWhileText_Digit_6[]  =     _("Wait for 6 hours");
static const u8 sWaitWhileText_Digit_12[] =     _("Wait for 9 hours");
static const u8 sWaitWhileText_Digit_9[]  =     _("Wait for 12 hours");
const u8 *const gWaitingText_DigitIndicator[] =
{
    sWaitWhileText_Digit_3,
    sWaitWhileText_Digit_6,
    sWaitWhileText_Digit_9,
    sWaitWhileText_Digit_12,
};

static const s32 sHourSegments[] =
{
    3,
    6,
    9,
    12,
};