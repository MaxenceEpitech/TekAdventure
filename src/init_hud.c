/*
** init_hud.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Sep 16 16:39:15 2017 maxence.fourrier
** Last update Sat Sep 23 00:05:40 2017 maxence.fourrier
*/

#include "explo.h"

sfSprite	**init_hud()
{
  sfSprite	**hud;

  if ((hud = malloc(sizeof(sfSprite *) * 4)) == NULL
      || (hud[SPR_OXY] = load_picture(PATH_OXY)) == NULL
      || (hud[SPR_POWER] = load_picture(PATH_POWER)) == NULL
      || (hud[SPR_HP] = load_picture(PATH_HP)) == NULL)
    return (NULL);
  hud[3] = NULL;
  return (hud);
}
