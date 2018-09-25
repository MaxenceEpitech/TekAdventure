/*
** use_item.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 19:00:52 2017 maxence.fourrier
** Last update Sat Oct  7 00:53:13 2017 maxence.fourrier
*/

#include "explo.h"

int		check_use(t_explo *explo, sfVector2i click,
			  sfVector2f click_map)
{
  int		item;

  if ((item = explo->player->inv[SIZE_INV_Y][0]->item) == 26
      && explo->player->power >= POWER_DRILL)
    if (mine(item, explo, click, click_map))
      return (1);
  return (SUCCESS);
}
