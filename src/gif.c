/*
** gif.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 13:01:42 2017 maxence.fourrier
** Last update Wed Sep 27 13:43:03 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_gif(t_explo *explo, int *i,
			 sfVector3f pos, sfVector2i gif)
{
  int		nb;

  if (*i == gif.x * gif.y)
    *i = 0;
  nb = *i / gif.y;
  pos.x += explo->player->pos.x - (SCREEN_WIDTH / 2);
  pos.y += explo->player->pos.y - (SCREEN_HEIGHT / 2);
  sfSprite_setPosition(explo->gif[(int)pos.z][nb], vector2f(pos.x, pos.y));
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[(int)pos.z][nb], NULL);
  *i = *i + 1;
}
