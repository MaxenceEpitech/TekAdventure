/*
** move.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 11 13:44:10 2017 maxence.fourrier
** Last update Sun Oct  8 11:05:30 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2f	get_dir_with_map(sfVector2f dir, sfVector2i size,
				 sfVector2f pos, int **map)
{
  sfVector2f	ret;

  if (pos.x + dir.x < MAP_BORDER * SPRITE_FLOOR_SIZE
      || pos.x + dir.x >= (size.x - MAP_BORDER) * SPRITE_FLOOR_SIZE)
    ret.x = 0;
  else
    ret.x = dir.x;
  if (pos.y + dir.y < MAP_BORDER * SPRITE_FLOOR_SIZE
      || pos.y + dir.y >= (size.y - MAP_BORDER) * SPRITE_FLOOR_SIZE)
    ret.y = 0;
  else
    ret.y = dir.y;
  if (ret.x == 0 && ret.y == 0)
    {
      dir.x = 0;
      dir.y = 0;
    }
  return (ret);
}

void		check_move_dir(t_explo *explo, t_placed_mod *placed,
			       sfVector2f pos, sfVector2f dir)
{
  while (placed != NULL)
    {
      if (pos.x + dir.x >= placed->pos.x
	  + explo->game->move_pos[placed->type]->top.x
	  && pos.x + dir.x <= placed->pos.x
	  + explo->game->move_pos[placed->type]->bot.x
	  && pos.y + dir.y >= placed->pos.y
	  + explo->game->move_pos[placed->type]->top.y
	  && pos.y + dir.y <= placed->pos.y
	  + explo->game->move_pos[placed->type]->bot.y)
	{
	  if (pos.x < placed->pos.x
	      + explo->game->move_pos[placed->type]->top.x
	      || pos.x > placed->pos.x
	      + explo->game->move_pos[placed->type]->bot.x)
	    explo->player->dir.x = 0;
	  if (pos.y < placed->pos.y
	      + explo->game->move_pos[placed->type]->top.y
	      || pos.y > placed->pos.y
	      + explo->game->move_pos[placed->type]->bot.y)
	    explo->player->dir.y = 0;
	}
      placed = placed->next;
    }
}

int		check_dir(t_explo *explo, sfVector2f dir, sfVector2f pos)
{
  if ((dir.x == 0
       && (dir.y <= HIT_SPEED_MIN && dir.y >= -HIT_SPEED_MIN))
      || (dir.y == 0
	  && (dir.x <= HIT_SPEED_MIN && dir.x >= -HIT_SPEED_MIN)))
    {
      explo->player->dir.x = 0;
      explo->player->dir.y = 0;
    }
  else if (((int)pos.x >= explo->player->click.x - PROB_ERROR
	    && (int)pos.x <= explo->player->click.x + PROB_ERROR
	    && (int)pos.y <= explo->player->click.y + PROB_ERROR
	    && (int)pos.y >= explo->player->click.y - PROB_ERROR))
    {
      explo->player->dir.x = 0;
      explo->player->dir.y = 0;
    }
  else
    {
      change_move_pos(explo);
      return (1);
    }
  return (SUCCESS);
}

int		move(t_explo *explo)
{
  sfVector2f	dir;

  if (check_dir(explo, explo->player->dir, explo->player->pos))
    {
      check_move_dir(explo, explo->game->placed,
		     explo->player->pos, explo->player->dir);
      if (!(explo->player->dir.x == 0 && explo->player->dir.y == 0))
	check_rock_dir(explo, explo->game->rock,
		       explo->player->pos, explo->player->dir);
      dir = get_dir_with_map(explo->player->dir, explo->game->size,
			     explo->player->pos, explo->game->map);
      sfView_move(explo->graph->view, dir);
      explo->player->pos = sfView_getCenter(explo->graph->view);
      if (!(explo->day->day > NB_HOUR / 2
	    && explo->day->day <= NB_HOUR))
	break_egg(explo);
    }
  return (SUCCESS);
}
