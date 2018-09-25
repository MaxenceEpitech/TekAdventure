/*
** mine_rock.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 23:48:36 2017 maxence.fourrier
** Last update Thu Oct 12 18:55:31 2017 maxence.fourrier
*/

#include "explo.h"

int		check_rock(t_explo *explo, t_pos *rock,
			   sfVector2f click)
{
  if (click.x >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x
      && click.x < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x
      && click.y >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y
      && click.x < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  return (SUCCESS);
}

int		is_a_rock(t_explo *explo, sfVector2i click,
			  t_pos *rock)
{
  while (rock != NULL)
    {
      if (rock->vec.x == click.x
	  && rock->vec.y == click.y
	  && rock->alive == 1)
	{
	  rock->alive = 0;
	  return (1);
	}
      rock = rock->next;
    }
  return (SUCCESS);
}

int		mine_rock(t_explo *explo, sfVector2f click_map,
			  sfVector2i map_pos)
{
  if (is_a_rock(explo, map_pos, explo->game->rock))
    {
      effect_drill(explo);
      explo->player->power -= POWER_DRILL;
      add_item_inv_console(explo->player->inv, 0, 1);
      draw_power(explo);
      wait_mouse(explo->graph->window);
      return (1);
    }
  return (SUCCESS);
}
