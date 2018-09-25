/*
** check_inv.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 21 11:14:50 2017 maxence.fourrier
** Last update Sun Oct  8 23:13:27 2017 jean-baptiste
*/

#include "explo.h"

int		del_item_inv_quantity(t_inv ***inv, sfVector2i pos,
				      int *quantity)
{
  if (inv[pos.y][pos.x]->quantity < *quantity)
    {
      *quantity -= inv[pos.y][pos.x]->quantity;
      inv[pos.y][pos.x]->quantity = -1;
      inv[pos.y][pos.x]->item = -1;
    }
  else if (*quantity < 9
	   && inv[pos.y][pos.x]->quantity > *quantity)
    {
      inv[pos.y][pos.x]->quantity -= *quantity;
      return (1);
    }
  else if (*quantity < 9
	   && inv[pos.y][pos.x]->quantity == *quantity)
    {
      inv[pos.y][pos.x]->quantity = -1;
      inv[pos.y][pos.x]->item = -1;
      return (1);
    }
  return (SUCCESS);
}

int		use_inv_item(t_inv ***inv, int item, int quantity)
{
  sfVector2i	pos;

  pos.y = -1;
  while (inv[++pos.y] && (pos.x = -1))
    while (inv[pos.y][++pos.x])
      if (inv[pos.y][pos.x]->item == item
	  && inv[pos.y][pos.x]->quantity > 0)
	{
	  if (quantity >= 9)
	    {
	      quantity -= inv[pos.y][pos.x]->quantity;
	      inv[pos.y][pos.x]->quantity = -1;
	      inv[pos.y][pos.x]->item = -1;
	    }
	  else if (quantity < 9)
	    if (del_item_inv_quantity(inv, pos, &quantity))
	      return (SUCCESS);
	}
  return (SUCCESS);
}

sfVector2i	inv_has_place(t_explo *explo, int item)
{
  sfVector2i	pos;

  pos.y = -1;
  item += 19;
  while (explo->player->inv[++pos.y] && (pos.x = -1))
    while (explo->player->inv[pos.y][++pos.x])
      if (explo->player->inv[pos.y][pos.x]->item == item
	  && explo->player->inv[pos.y][pos.x]->quantity < STACK_SIZE)
        return (pos);
  pos.y = -1;
  while (explo->player->inv[++pos.y] && (pos.x = -1))
    while (explo->player->inv[pos.y][++pos.x])
      if (explo->player->inv[pos.y][pos.x]->item == -1)
        return (pos);
  pos.x = -1;
  return (pos);
}

int		inv_contain(t_explo *explo, int item)
{
  int		x;
  int		y;
  int		cpt;

  y = 0;
  cpt = 0;
  while (explo->player->inv[y])
    {
      x = 0;
      while (explo->player->inv[y][x])
        {
          if (explo->player->inv[y][x]->item == item)
            cpt += explo->player->inv[y][x]->quantity;
          x++;
        }
      y++;
    }
  return (cpt);
}
