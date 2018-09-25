/*
** add_item_inv.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 19:36:48 2017 maxence.fourrier
** Last update Thu Oct  5 01:05:07 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2i	inv_had_place_console(t_inv ***inv, int item)
{
  sfVector2i	cpt;

  cpt.y = -1;
  while (inv[++cpt.y] && (cpt.x = -1))
    while (inv[cpt.y][++cpt.x])
      if (inv[cpt.y][cpt.x]->item == item
	  && inv[cpt.y][cpt.x]->quantity < STACK_SIZE)
	return (cpt);
  cpt.y = -1;
  while (inv[++cpt.y] && (cpt.x = -1))
    while (inv[cpt.y][++cpt.x])
      if (inv[cpt.y][cpt.x]->item == -1
	  && inv[cpt.y][cpt.x]->quantity == -1)
	return (cpt);
  return (vector2i(-1, -1));
}

int		add_item_inv_console(t_inv ***inv, int item, int amount)
{
  sfVector2i	pos;
  int		save;

  save = 0;
  pos = inv_had_place_console(inv, item);
  while (amount > 0 && pos.x != -1)
    {
      if (inv[pos.y][pos.x]->quantity == -1
	  && amount > 0)
	inv[pos.y][pos.x]->quantity = 0;
      while (inv[pos.y][pos.x]->quantity < STACK_SIZE
	     && amount > 0)
	{
	  amount--;
	  save++;
	  inv[pos.y][pos.x]->quantity++;
	  inv[pos.y][pos.x]->item = item;
	}
      pos = inv_had_place_console(inv, item);
    }
  return (save);
}
