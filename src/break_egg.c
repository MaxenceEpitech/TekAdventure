/*
** break_egg.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct  7 18:06:00 2017 maxence.fourrier
** Last update Thu Oct 12 19:36:49 2017 maxence.fourrier
*/

#include "explo.h"

void		break_egg(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i])
    if (explo->game->mob[i]->type == 0
        && get_dist_btw(explo->game->mob[i]->pos,
			explo->player->pos) < RANGE_EGG_BREAK)
      {
	effect_egg(explo);
	explo->game->mob[i]->type++;
      }
}
