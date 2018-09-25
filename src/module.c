/*
** module.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
**
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Sep 23 18:59:36 2017 maxence.fourrier
** Last update Sun Oct  8 22:29:35 2017 maxence.fourrier
*/

#include "explo.h"

static t_ptr	g_ptr[10] =
  {
    {MODULE_BASE, base},
    {MODULE_SOLAR, solar},
    {MODULE_CHEST, chest},
    {MODULE_COAL, coal},
    {MODULE_NUCLEAR, nuclear},
    {MODULE_LAUNCHER, launcher},
    {MODULE_FUSION, fusion},
    {MODULE_LASER, laser},
    {-1}
  };

int		check_dist(t_limit **limit, t_explo *explo,
			   t_placed_mod *placed)
{
  int		i;

  i = -1;
  while (g_ptr[++i].nb != -1)
    if (g_ptr[i].nb == placed->type)
      if (g_ptr[i].fnc(explo, placed) != 0)
	return (1);
  explo->player->dir.x = 0;
  explo->player->dir.y = 0;
  return (SUCCESS);
}

int		click_module(sfVector2f click_map, t_explo *explo,
			     t_limit **limit, t_placed_mod *placed)
{
  while (placed != NULL)
    {
      if (click_map.x <= placed->pos.x
          + limit[placed->type]->bot.x
          && click_map.x >= placed->pos.x
          + limit[placed->type]->top.x
          && click_map.y <= placed->pos.y
          + limit[placed->type]->bot.y
          && click_map.y >= placed->pos.y
          + limit[placed->type]->top.y)
	{
	  if (check_dist(limit, explo, placed))
	    return (1);
	  else
	    return (SUCCESS);
	}
      placed = placed->next;
    }
  return (SUCCESS);
}

int		check_dist_other_placed(sfVector2f click, t_placed_mod *placed,
					t_limit **limit, int item)
{
  while (placed != NULL)
    {
      if (can_place_center(click, limit, placed, item)
	  || can_place_top_right(click, limit, placed, item)
	  || can_place_top_left(click, limit, placed, item)
	  || can_place_bot_right(click, limit, placed, item)
	  || can_place_bot_left(click, limit, placed, item))
	return (SUCCESS);
      placed = placed->next;
    }
  return (1);
}

void		remove_placed_item(t_explo *explo)
{
  if (explo->player->inv[SIZE_INV_Y][0]->quantity > 1)
    explo->player->inv[SIZE_INV_Y][0]->quantity--;
  else
    {
      explo->player->inv[SIZE_INV_Y][0]->item = -1;
      explo->player->inv[SIZE_INV_Y][0]->quantity = -1;
    }
  wait_mouse(explo->graph->window);
}

int		place_module(t_explo *explo, sfVector2f click_map)
{
  sfVector2i	click;
  int		item;

  if ((item = explo->player->inv[SIZE_INV_Y][0]->item - 19) < 0
      || item == 8 || item == 9)
    return (SUCCESS);
  click_map.x -= (explo->game->limit[item]->bot.x / 2);
  click_map.y -= (explo->game->limit[item]->bot.y / 2);
  if (explo->player->inv[SIZE_INV_Y][0]->item >= 20
      && explo->player->inv[SIZE_INV_Y][0]->item != SPR_I_DRILL
      && check_dist_other_placed(click_map, explo->game->placed,
				 explo->game->limit, item)
      && can_place_rock(explo->game->rock, click_map, item, explo)
      && can_place_lake(explo->game->mountain, click_map, item, explo))
    {
      explo->game->placed
	= add_to_placed(vector2i(click_map.x, click_map.y),
			explo->game->base, item, explo->game->placed);
      remove_placed_item(explo);
      return (1);
    }
  return (SUCCESS);
}
