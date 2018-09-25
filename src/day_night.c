/*
** day_night.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 24 12:52:57 2017 maxence.fourrier
** Last update Wed Oct 11 16:23:03 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_game_time(t_explo *explo)
{
  sfSprite_setPosition(explo->graph->time,
		       vector2f(explo->player->pos.x -
				(SCREEN_WIDTH / 2),
				explo->player->pos.y -
				(SCREEN_HEIGHT / 2)));
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->graph->time, NULL);
}

void		change_day_time_morning(t_explo *explo, int i)
{
  sfVector2i	cpt;

  explo->day->minute = i;
  cpt.y = -1;
  while (++cpt.y < SCREEN_HEIGHT && (cpt.x = -1))
    while (++cpt.x < SCREEN_WIDTH)
      my_put_pixel(explo->graph->framebuffer_time, cpt.x, cpt.y,
		   sfColor_fromRGBA(0, 0, 0, 4 * i));
  sfTexture_updateFromPixels(explo->graph->tex_time,
                             explo->graph->framebuffer_time->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		change_day_time_night(t_explo *explo, int i)
{
  sfVector2i	cpt;

  explo->day->minute = i;
  cpt.y = -1;
  while (++cpt.y < SCREEN_HEIGHT && (cpt.x = -1))
    while (++cpt.x < SCREEN_WIDTH)
      my_put_pixel(explo->graph->framebuffer_time, cpt.x, cpt.y,
		   sfColor_fromRGBA(0, 0, 0, 240 - (4 * i)));
  sfTexture_updateFromPixels(explo->graph->tex_time,
                             explo->graph->framebuffer_time->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

int		game_time(t_explo *explo)
{
  if (explo->game->time > explo->day->time + HOUR / NB_MINUTE)
    {
      if (++explo->day->minute >= NB_MINUTE)
	{
	  explo->day->minute = 0;
	  if (++explo->day->day >= NB_HOUR)
	    explo->day->day = 0;
	}
      if (explo->day->day == 0)
	change_day_time_night(explo, explo->day->minute);
      else if (explo->day->day == NB_HOUR / 2)
	change_day_time_morning(explo, explo->day->minute);
      explo->day->time = explo->game->time;
    }
}
