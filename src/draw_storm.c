/*
** draw_storm.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct  3 21:51:23 2017 maxence.fourrier
** Last update Wed Oct  4 15:25:49 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_gif_storm(t_explo *explo, int *i,
			       sfVector3f pos, sfVector2i gif)
{
  int		nb;

  if (*i == gif.x * gif.y)
    *i = 0;
  nb = *i / gif.y;
  pos.x -= 175;
  pos.y -= 130;
  sfSprite_setPosition(explo->gif[(int)pos.z][nb], vector2f(pos.x, pos.y));
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[(int)pos.z][nb], NULL);
  *i = *i + 1;
}

void		draw_storm(t_explo *explo, t_storm *storm)
{
  int		i;

  i = -1;
  while (storm->obj[++i])
    if (storm->obj[i]->alive)
      {
	draw_gif_storm(explo, &(storm->obj[i]->cpt),
		       vector3f(storm->obj[i]->pos.x,
				storm->obj[i]->pos.y,
				GIF_9),
		       vector2i(GIF_9_TOTAL, GIF_9_TIME));
	storm->obj[i]->pos.x += storm->obj[i]->dir.x;
	storm->obj[i]->pos.y += storm->obj[i]->dir.y;
      }
}
