/*
** draw_placed.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 10:01:03 2017 maxence.fourrier
** Last update Mon Oct  9 13:28:18 2017 maxence.fourrier
*/

#include "explo.h"

void		init_placed_draw(t_placed_mod *placed)
{
  while (placed != NULL)
    {
      placed->draw = 0;
      placed = placed->next;
    }
}

void		draw_undraw_placed(t_explo *explo,
				   t_placed_mod *placed)
{
  while (placed != NULL)
    {
      if (placed->draw == 0 && placed->type != MODULE_LASER)
	{
          sfSprite_setPosition(explo->placed[placed->type],
                               vector2f(placed->pos.x, placed->pos.y));
          sfRenderWindow_drawSprite(explo->graph->window,
                                    explo->placed[placed->type], NULL);
        }
      if (placed->draw == 0 && placed->type == MODULE_LASER)
	draw_laser_tower(explo, placed);
      placed = placed->next;
    }
}

void		draw_placed_type(t_explo *explo, t_placed_mod *placed)
{
  if (placed->type != MODULE_LASER)
    {
      placed->draw = 1;
      sfSprite_setPosition(explo->placed[placed->type],
			   vector2f(placed->pos.x, placed->pos.y));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->placed[placed->type], NULL);
    }
  else if (placed->type == MODULE_LASER)
    {
      draw_laser_tower(explo, placed);
      placed->draw = 1;
    }
}

void		draw_placed(t_explo *explo, t_placed_mod *placed,
			    sfVector2f pos)
{
  while (placed != NULL)
    {
      if (get_dist_btw(explo->player->pos,
                       vector2f(placed->pos.x, placed->pos.y)) < 1000
	  && pos.y > placed->pos.y
	  + explo->game->move_pos[placed->type]->top.y)
	draw_placed_type(explo, placed);
      placed = placed->next;
    }
}
