/*
** upgrade_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 19:21:46 2017 maxence.fourrier
** Last update Wed Oct 11 19:01:00 2017 maxence.fourrier
*/

#include "explo.h"

void		del_inv(t_inv ***inv, int item, int ammount)
{
  sfVector2i	vec;

  vec.y = -1;
  while (ammount > 0 && ++vec.y <= SIZE_INV_Y && (vec.x = -1))
    while (++vec.x < SIZE_INV_X)
      {
	if (inv[vec.y][vec.x]->item == item)
	  {
	    while (inv[vec.y][vec.x]->quantity > 0
		   && ammount > 0)
	      {
		inv[vec.y][vec.x]->quantity--;
		ammount--;
	      }
	    if (inv[vec.y][vec.x]->quantity == 0)
	      {
		inv[vec.y][vec.x]->quantity = -1;
		inv[vec.y][vec.x]->item = -1;
	      }
	  }
      }
}

int		can_upgrade(t_explo *explo, int *upgrade)
{
  int		i;

  i = 0;
  if (upgrade == NULL)
    return (SUCCESS);
  while (upgrade[i] != -1)
    {
      if (inv_contain(explo, i + 1) < upgrade[i])
	return (SUCCESS);
      i++;
    }
  return (1);
}

int		can_link(t_placed_mod *placed, t_explo *explo)
{
  if (inv_contain(explo, COPPER - '0' + 1) >= placed->link_cost)
    return (1);
  return (SUCCESS);
}
