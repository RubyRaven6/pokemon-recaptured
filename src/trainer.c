#include "global.h"
#include "constants/trainers.h"

static enum TrainerPicID GetEmeraldTrainerPic(enum PlayerGender gender)
{    
    switch(gender)
    {
        case GENDER_MASCULINE:
            return TRAINER_PIC_BRENDAN;
        case GENDER_ANDROGYNOUS:
            return TRAINER_PIC_KRIS;
        default: //happy women's month
        case GENDER_FEMININE:
            return TRAINER_PIC_MAY;
    }
}
static enum TrainerPicID GetRSTrainerPic(enum PlayerGender gender)
{
    return gender == GENDER_MASCULINE ? TRAINER_PIC_RS_BRENDAN : TRAINER_PIC_RS_MAY;
}

static enum TrainerPicID GetKantoTrainerPic(enum PlayerGender gender)
{
    return gender == GENDER_MASCULINE ? TRAINER_PIC_RED : TRAINER_PIC_LEAF;
}

enum TrainerPicID GetPlayerTrainerPic(enum PlayerGender gender, enum GameVersion version)
{
    switch (version)
    {
        case VERSION_SAPPHIRE:
        case VERSION_RUBY:
            return GetRSTrainerPic(gender);
        case VERSION_LEAF_GREEN:
        case VERSION_FIRE_RED:
            return GetKantoTrainerPic(gender);
        case VERSION_EMERALD:
        default:
            return GetEmeraldTrainerPic(gender);
    }
}
