/*
** draw_laser_tower.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  9 09:44:01 2017 maxence.fourrier
** Last update Thu Oct 12 19:41:50 2017 maxence.fourrier
*/

#include <math.h>
#include "explo.h"

void		draw_laser_gif(t_explo *explo, t_placed_mod *placed,
			       t_mob *mob, int angle)
{
  effect_laser(explo, placed->link);
  placed->upgrade++;
  if (placed->upgrade > GIF_16_TIME)
    {
      placed->upgrade = 0;
      placed->link++;
    }
  if (placed->link >= GIF_16_TOTAL)
    placed->link = 0;
  angle += 20;
  sfSprite_setPosition(explo->gif[GIF_16][placed->link],
		       vector2f(placed->pos.x, placed->pos.y));
  sfSprite_setOrigin(explo->gif[GIF_16][placed->link], vector2f(392, 92));
  sfSprite_setRotation(explo->gif[GIF_16][placed->link], angle);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[GIF_16][placed->link], NULL);
  if (placed->link == 110 && placed->furnace.x == 1)
    kill_mob(placed, mob, explo);
  placed->furnace.x = 1;
}

t_mob		*bird_in_range(t_mob **mob, sfVector2i placed,
			       int *dist)
{
  int		i;

  i = -1;
  while (mob[++i] != NULL)
    if (mob[i]->type >= 1
	&& (*dist = get_dist_btw(vector2f(mob[i]->pos.x,
					  mob[i]->pos.y),
				 vector2f(placed.x,
					  placed.y))) < 500)
      return (mob[i]);
  return (NULL);
}

void		bird_is_in_range(t_explo *explo, t_placed_mod *placed,
				 int dist, t_mob *mob)
{
  sfVector2f	dir;

  if (dist != 0)
    dir = vector2f((placed->pos.x
		    - mob->pos.x) / dist,
		   (placed->pos.y
		    - mob->pos.y) / dist);
  else
    dir = vector2f(0, 0);
  placed->angle = atan2(dir.y, dir.x) / M_PI * 180;
  draw_laser_gif(explo, placed, mob, placed->angle);
}

void		draw_laser_tower(t_explo *explo, t_placed_mod *placed)
{
  t_mob		*mob;
  int		dist;

  mob = bird_in_range(explo->game->mob, placed->pos, &dist);
  if (mob != NULL)
    bird_is_in_range(explo, placed, dist, mob);
  else
    bird_not_in_range(explo, placed);
}
