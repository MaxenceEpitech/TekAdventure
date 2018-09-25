/*
** placed_module.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
**
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 19 19:23:48 2017 maxence.fourrier
** Last update Mon Oct  9 14:34:09 2017 maxence.fourrier
*/

#include "explo.h"

void		change_inv_placed(t_inv ***inv)
{
  inv[0][0]->quantity = 0;
  inv[0][0]->item = 0;
  inv[0][1]->quantity = 0;
  inv[0][1]->item = 0;
  inv[0][2]->quantity = 0;
  inv[0][2]->item = 0;
}

t_placed_mod	*add_to_placed(sfVector2i pos, sfVector2i base,
			       int type, t_placed_mod *list)
{
  t_placed_mod	*new;

  if ((new = malloc(sizeof(t_placed_mod))) == NULL
      || (new->inv = init_inv()) == NULL)
    return (NULL);
  new->furnace = vector2i(0, 0);
  new->next = list;
  new->pos = vector2i(pos.x, pos.y);
  new->type = type;
  new->upgrade = 0;
  new->link = 0;
  new->on = 0;
  new->angle = 0;
  new->link_cost = get_dist_btw(vector2f(base.x, base.y),
				vector2f(new->pos.x, new->pos.y))
    / 700 + 1;
  new->circle = create_circle(vector2f(pos.x, pos.y), sfRed, 200);
  if (new->type != MODULE_CHEST)
    change_inv_placed(new->inv);
  return (new);
}

t_placed_mod	*del_from_placed(t_placed_mod *placed, sfVector2i pos)
{
  t_placed_mod	*new;

  if (placed == NULL
      || (new = malloc(sizeof(t_placed_mod))) == NULL)
    return (NULL);
  new = placed;
  while (placed->next != NULL)
    {
      if (placed->next->pos.x == pos.x
	  && placed->next->pos.y == pos.y)
	placed->next = placed->next->next;
      placed = placed->next;
    }
  return (new);
}
