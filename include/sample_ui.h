#ifndef SAMPLE_UI_H
#define SAMPLE_UI_H

#include "gba/types.h"
#include "main.h"

/*
 * Entry tasks for the different versions of the UI. In `start_menu.c', we'll launch a task using one of
 * these functions. You can change which is used to change which menu is launched.
 */

// Launch the basic version of the UI
void Task_OpenSampleUi_StartHere(u8 taskId);

// Launch the sliding panel version of the UI
void Task_OpenSampleUi_SlidingPanel(u8 taskId);

// Launch the blank template version of the UI
void Task_OpenSampleUi_BlankTemplate(u8 taskId);

#endif
