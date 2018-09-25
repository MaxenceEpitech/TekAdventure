/*
** draw_map.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 09:42:09 2017 maxence.fourrier
** Last update Sun Oct  8 14:55:30 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_sprite_map(t_explo *explo, sfVector2i cpt)
{
  if (explo->game->depth[cpt.y][cpt.x] == 0)
    {
      sfSprite_setPosition(explo->floor[0][explo->game->map[cpt.y][cpt.x]],
			   vector2f(cpt.x * SPRITE_FLOOR_SIZE,
				    cpt.y * SPRITE_FLOOR_SIZE));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->floor[0]
				[explo->game->map[cpt.y][cpt.x]], NULL);
      return ;
    }
  sfSprite_setPosition(explo->floor[explo->game->depth[cpt.y][cpt.x]]
		       [explo->game->ore[explo->game->depth
					 [cpt.y][cpt.x] - 1]
			[cpt.y][cpt.x] - '0' + 1],
		       vector2f(cpt.x * SPRITE_FLOOR_SIZE, cpt.y
				* SPRITE_FLOOR_SIZE));
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->floor[explo->game->depth[cpt.y][cpt.x]]
			    [explo->game->ore[explo->game->depth
					      [cpt.y][cpt.x] - 1]
			     [cpt.y][cpt.x] - '0' + 1]
			    , NULL);
}

void		draw_map(t_explo *explo)
{
  int		save;
  sfVector2i	cpt;
  sfVector2i	max;

  max = init_draw_max(explo);
  cpt.y = init_draw_cpt_y(explo);
  save = init_draw_cpt_x(explo);
  while (cpt.y < max.y)
    {
      cpt.x = save;
      while (cpt.x < max.x)
        {
          draw_sprite_map(explo, cpt);
          cpt.x++;
        }
      cpt.y++;
    }
}
