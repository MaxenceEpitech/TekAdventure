/*
** init_floor.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 09:44:54 2017 maxence.fourrier
** Last update Sun Oct  8 13:49:59 2017 maxence.fourrier
*/

#include "explo.h"

sfSprite	**init_ore_first()
{
  sfSprite	**ore;

  if ((ore = malloc(sizeof(sfSprite *) * NB_FLOOR)) == NULL
      || (ore[SPR_F_0_0] = load_picture(PATH_F_0_0)) == NULL
      || (ore[SPR_F_0_1] = load_picture(PATH_F_0_1)) == NULL
      || (ore[SPR_F_0_2] = load_picture(PATH_F_0_2)) == NULL
      || (ore[SPR_F_0_3] = load_picture(PATH_F_0_3)) == NULL
      || (ore[SPR_F_0_4] = load_picture(PATH_F_0_4)) == NULL
      || (ore[SPR_F_0_5] = load_picture(PATH_F_0_5)) == NULL
      || (ore[SPR_F_0_6] = load_picture(PATH_F_0_6)) == NULL
      || (ore[SPR_F_0_7] = load_picture(PATH_F_0_7)) == NULL)
    return (NULL);
  ore[8] = NULL;
  return (ore);
}

sfSprite	**init_ore_second()
{
  sfSprite	**ore;

  if ((ore = malloc(sizeof(sfSprite *) * NB_FLOOR)) == NULL
      || (ore[SPR_F_1_0] = load_picture(PATH_F_1_0)) == NULL
      || (ore[SPR_F_1_1] = load_picture(PATH_F_1_1)) == NULL
      || (ore[SPR_F_1_2] = load_picture(PATH_F_1_2)) == NULL
      || (ore[SPR_F_1_3] = load_picture(PATH_F_1_3)) == NULL
      || (ore[SPR_F_1_4] = load_picture(PATH_F_1_4)) == NULL
      || (ore[SPR_F_1_5] = load_picture(PATH_F_1_5)) == NULL
      || (ore[SPR_F_1_6] = load_picture(PATH_F_1_6)) == NULL
      || (ore[SPR_F_1_7] = load_picture(PATH_F_1_7)) == NULL)
    return (NULL);
  ore[8] = NULL;
  return (ore);
}

sfSprite	**init_ore_last()
{
  sfSprite	**ore;

  if ((ore = malloc(sizeof(sfSprite *) * NB_FLOOR)) == NULL
      || (ore[SPR_F_2_0] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_1] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_2] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_3] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_4] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_5] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_6] = load_picture(PATH_F_2_0)) == NULL
      || (ore[SPR_F_2_7] = load_picture(PATH_F_2_0)) == NULL)
    return (NULL);
  ore[8] = NULL;
  return (ore);
}

sfSprite	**init_floor_first()
{
  sfSprite	**floor;

  if ((floor = malloc(sizeof(sfSprite *) * NB_FLOOR)) == NULL
      || (floor[SPR_F_0] = load_picture(PATH_F_0)) == NULL
      || (floor[SPR_F_1] = load_picture(PATH_F_1)) == NULL
      || (floor[SPR_F_2] = load_picture(PATH_F_2)) == NULL)
    return (NULL);
  floor[3] = NULL;
  return (floor);
}

sfSprite	***init_floor()
{
  sfSprite	***floor;

  if ((floor = malloc(sizeof(sfSprite **) * DEPTH)) == NULL
      || (floor[0] = init_floor_first(floor)) == NULL
      || (floor[1] = init_ore_first(floor)) == NULL
      || (floor[2] = init_ore_second(floor)) == NULL
      || (floor[3] = init_ore_last(floor)) == NULL)
    return (NULL);
  floor[4] = NULL;
  return (floor);
}
