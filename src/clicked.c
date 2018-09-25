/*
** clicked.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep  8 19:46:40 2017 maxence.fourrier
** Last update Sun Oct  8 19:49:50 2017 maxence.fourrier
*/

#include "explo.h"

void		change_move_pos(t_explo *explo)
{
  int		dist;

  dist = get_dist_btw(vector2f(explo->player->click.x,
			       explo->player->click.y),
		      explo->player->pos);
  explo->player->dir.x = (explo->player->click.x
			  - explo->player->pos.x) / dist;
  explo->player->dir.y = (explo->player->click.y
			  - explo->player->pos.y) / dist;
}

int		get_obj_clicked_right(t_explo *explo)
{
  sfVector2i	click;
  sfVector2f	click_map;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  if (click.x < 0 || click.x > SCREEN_WIDTH
      || click.y < 0 || click.y > SCREEN_HEIGHT)
    return (SUCCESS);
  click_map = sfRenderWindow_mapPixelToCoords(explo->graph->window,
					      click, explo->graph->view);
  if (click_module(click_map, explo, explo->game->limit, explo->game->placed))
    return (1);
  if (check_use(explo, click, click_map)
      || place_module(explo, click_map))
    return (SUCCESS);
  return (SUCCESS);
}

int		get_obj_clicked_left(t_explo *explo)
{
  sfVector2i	click;
  sfVector2f	click_map;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  if (click.x < 0 || click.x > SCREEN_WIDTH
      || click.y < 0 || click.y > SCREEN_HEIGHT)
    return (SUCCESS);
  click_map = sfRenderWindow_mapPixelToCoords(explo->graph->window,
					      click, explo->graph->view);
  explo->player->click = vector2i(click_map.x, click_map.y);
  change_move_pos(explo);
  return (SUCCESS);
}
