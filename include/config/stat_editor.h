#ifndef GUARD_INCLUDE_CONSTANTS_STAT_EDITOR_H
#define GUARD_INCLUDE_CONSTANTS_STAT_EDITOR_H

#define P_STAT_EDITOR_ENABLE                TRUE  // If TRUE, a stat editor will be available to use to modify stats of a party Pokémon.

#define P_STAT_EDITOR_ALWAYS                TRUE  // If TRUE, the stat editor will always be available. Overrides `P_FLAG_STAT_EDITOR`
#define P_FLAG_STAT_EDITOR_GET              0     // If this flag is set, the stat editor will be available to use.

// Accessibility
// Please only enable either Party Menu or Summary Screen. I have not tested (nor will I ever test) Start Menu.
#define P_PARTY_MENU_STAT_EDITOR            FALSE // If TRUE, the stat editor will be accessible through the party menu. (opens on selected Pokémon)
#define P_START_MENU_STAT_EDITOR            FALSE // If TRUE, the stat editor will be accessible through the start menu. (opens on first Pokémon)
#define P_SUMMARY_SCREEN_STAT_EDITOR        TRUE  // If TRUE, the stat editor will be accessible through the summary screen on the stat menu by clicking Start. (opens on selected Pokémon)

// Hidden Power or Terastal Config
#define P_STAT_EDITOR_HP_OR_TERA    P_STAT_EDITOR_TERASTAL

// defines for the config above
#define P_STAT_EDITOR_NONE          0 // neither will be available
#define P_STAT_EDITOR_HIDDEN_POWER  1 // allows change of Hidden Power type (affects IVs)
#define P_STAT_EDITOR_TERASTAL      2 // allows change of Tera Type

// General Configs
#define P_STAT_EDITOR_NATURE_ARROWS         TRUE  // If TRUE, stats increased or decreased by nature will have arrows, red and up = increased, blue and down = decreased.
#define P_STAT_EDITOR_MOVE_RELEARNER        TRUE  // If TRUE, the move relearner will be accessible through the stat editor by pressing Start.
#define P_STAT_EDITOR_CYCLE_MODE            TRUE  // If TRUE, allows stat editor to cycle through the party or box.
#define P_STAT_EDITOR_CENTER_ALIGN_TEXT     TRUE  // If TRUE, center aligns texts such as nickname, ability and nature.
#define P_STAT_EDITOR_CENTER_ALIGN_STATS    FALSE // If TRUE, center aligns all stat numbers.

// UI Configs
#define P_STAT_EDITOR_SCROLLING_BG          TRUE  // If TRUE, enables scrolling animated background.
#define P_STAT_EDITOR_BG_BLEND              FALSE // If TRUE, enables alpha blending for the main UI (semi-transparency)
#define P_STAT_EDITOR_MON_IDLE_ANIMS        TRUE  // If TRUE, loops the Pokémon animations regularly as an "idle" anim.
#define P_STAT_EDITOR_MON_IDLE_ANIMS_FRAMES 300   // Number of frames between each idle anim if P_STAT_EDITOR_MON_IDLE_ANIMS is TRUE.
#define P_STAT_EDITOR_MON_SHADOWS           TRUE  // If TRUE, displays a shadow for the Pokémon sprite.

#endif // GUARD_INCLUDE_CONSTANTS_STAT_EDITOR_H
