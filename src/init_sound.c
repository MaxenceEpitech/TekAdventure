/*
** init_sound.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 13 12:36:19 2017 maxence.fourrier
** Last update Fri Oct 13 12:42:29 2017 maxence.fourrier
*/

#include "explo.h"

sfMusic		**init_music_other_other_other(sfMusic **music)
{
  if ((music[SND_DEATH1]
       = sfMusic_createFromFile(PATH_SND_DEATH1)) == NULL
      || (music[SND_DEATH2]
          = sfMusic_createFromFile(PATH_SND_DEATH2)) == NULL
      || (music[SND_DEATH3]
          = sfMusic_createFromFile(PATH_SND_DEATH3)) == NULL)
    return (NULL);
  music[34] = NULL;
  return (music);
}

sfMusic		**init_music_other_other(sfMusic **music)
{
  if ((music[SND_EVACUATE]
       = sfMusic_createFromFile(PATH_SND_EVACUATE)) == NULL
      || (music[SND_DESTROY]
          = sfMusic_createFromFile(PATH_SND_DESTROY)) == NULL
      || (music[SND_BFR_SIREN]
          = sfMusic_createFromFile(PATH_SND_BFR_SIREN)) == NULL
      || (music[SND_DI1]
          = sfMusic_createFromFile(PATH_SND_DI1)) == NULL
      || (music[SND_DI2]
          = sfMusic_createFromFile(PATH_SND_DI2)) == NULL
      || (music[SND_DI3]
          = sfMusic_createFromFile(PATH_SND_DI3)) == NULL
      || (music[SND_INJ1]
          = sfMusic_createFromFile(PATH_SND_INJ1)) == NULL
      || (music[SND_INJ2]
          = sfMusic_createFromFile(PATH_SND_INJ2)) == NULL
      || (music[SND_INJ3]
          = sfMusic_createFromFile(PATH_SND_INJ3)) == NULL
      || (music = init_music_other_other_other(music)) == NULL)
    return (NULL);
  return (music);
}

sfMusic		**init_music_other(sfMusic **music)
{
  if ((music[SND_FUSION]
       = sfMusic_createFromFile(PATH_SND_FUSION)) == NULL
      || (music[SND_LASER]
          = sfMusic_createFromFile(PATH_SND_LASER)) == NULL
      || (music[SND_DRILL_1]
          = sfMusic_createFromFile(PATH_SND_DRILL_1)) == NULL
      || (music[SND_DRILL_2]
          = sfMusic_createFromFile(PATH_SND_DRILL_2)) == NULL
      || (music[SND_EGG_EXPLO]
          = sfMusic_createFromFile(PATH_SND_EGG_EXPLO)) == NULL
      || (music[SND_DIE_BIRD]
          = sfMusic_createFromFile(PATH_SND_DIE_BIRD)) == NULL
      || (music[SND_CRASH]
          = sfMusic_createFromFile(PATH_SND_CRASH)) == NULL
      || (music[SND_SIREN]
          = sfMusic_createFromFile(PATH_SND_SIREN)) == NULL
      || (music[SND_INC]
          = sfMusic_createFromFile(PATH_SND_INC)) == NULL
      || (music = init_music_other_other(music)) == NULL)
    return (NULL);
  return (music);
}

sfMusic		**init_music()
{
  sfMusic	**music;

  if ((music = malloc(sizeof(sfMusic *) * NB_SOUND)) == NULL
      || (music[SND_MENU] = sfMusic_createFromFile(PATH_SND_MENU)) == NULL
      || (music[SND_GAME_0] = sfMusic_createFromFile(PATH_GAME_0)) == NULL
      || (music[SND_GAME_1] = sfMusic_createFromFile(PATH_GAME_1)) == NULL
      || (music[SND_GAME_2] = sfMusic_createFromFile(PATH_GAME_2)) == NULL
      || (music[SND_GAME_3] = sfMusic_createFromFile(PATH_GAME_3)) == NULL
      || (music[SND_GAME_4] = sfMusic_createFromFile(PATH_GAME_4)) == NULL
      || (music[SND_GAME_5] = sfMusic_createFromFile(PATH_GAME_5)) == NULL
      || (music[SND_GAME_6] = sfMusic_createFromFile(PATH_GAME_6)) == NULL
      || (music[SND_GAME_7] = sfMusic_createFromFile(PATH_GAME_7)) == NULL
      || (music[SND_BASE]
          = sfMusic_createFromFile(PATH_SND_BASE)) == NULL
      || (music[SND_SOLAR]
          = sfMusic_createFromFile(PATH_SND_SOLAR)) == NULL
      || (music[SND_COAL]
          = sfMusic_createFromFile(PATH_SND_COAL)) == NULL
      || (music[SND_NUCLEAR]
          = sfMusic_createFromFile(PATH_SND_NUCLEAR)) == NULL
      || (music = init_music_other(music)) == NULL)
    return (NULL);
  return (music);
}

