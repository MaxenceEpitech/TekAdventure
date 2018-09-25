/*
** base.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 12:54:52 2017 maxence.fourrier
** Last update Wed Oct 11 19:32:52 2017 maxence.fourrier
*/

#include "explo.h"

t_placed_mod	*get_base_module(t_placed_mod *placed)
{
  while (placed->next != NULL)
    placed = placed->next;
  return (placed);
}

void		base_back(t_explo *explo, int *i, int *j, int *k)
{
  sfSprite_setPosition(explo->sprite[SPR_BLACK],
		       vector2f(explo->player->pos.x
				- (SCREEN_WIDTH / 2),
				explo->player->pos.y
				- (SCREEN_HEIGHT / 2)));
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_BLACK], NULL);
  draw_gif(explo, i, vector3f(100, 100, GIF_2),
	   vector2i(GIF_2_TOTAL, GIF_2_TIME));
  draw_gif(explo, j, vector3f(700, 100, GIF_2),
	   vector2i(GIF_2_TOTAL, GIF_2_TIME));
  draw_gif(explo, k, vector3f(1100, 445, GIF_3),
	   vector2i(GIF_3_TOTAL, GIF_3_TIME));
}

int		base(t_explo *explo, t_placed_mod *placed)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  j = 100;
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      if (click_upgrade(explo, vector2f(80, 470),
			explo->game->upgrade[MODULE_BASE][placed->upgrade]))
        wait_mouse(explo->graph->window);
      explo->game->time = get_time();
      regen(explo);
      base_back(explo, &i, &j, &k);
      draw_base(explo);
      sfRenderWindow_display(explo->graph->window);
      music_base(explo);
    }
  play_stop_music(explo, vector2i(0, 0), vector2i(1, SND_BASE), 0);
  return (SUCCESS);
}
