/*
** give.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 12 19:08:33 2017 maxence.fourrier
** Last update Thu Oct 12 19:14:54 2017 maxence.fourrier
*/

#include "explo.h"

int		give_health(char **tab, t_explo *explo)
{
  explo->player->hp = 100;
  draw_hp(explo);
}

int		give_power(char **tab, t_explo *explo)
{
  explo->player->power = 100;
  draw_power(explo);
}

int		give_oxygen(char **tab, t_explo *explo)
{
  explo->player->oxy = 100;
  draw_oxygen(explo);
}
