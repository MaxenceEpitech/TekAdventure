/*
** intro.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 11:49:19 2017 maxence.fourrier
** Last update Sat Oct 14 12:55:18 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_intro(t_explo *explo, sfVector2f pos, int image)
{
  sfSprite_setPosition(explo->gif[GIF_15][image], pos);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[GIF_15][image], NULL);
  sfRenderWindow_display(explo->graph->window);
}

void		loading(t_explo *explo)
{
  int		i;
  int		nb;
  sfVector2i	vec;

  i = 0;
  nb = 0;
  vec = vector2i((SCREEN_WIDTH / 2) - 400,
		 (SCREEN_HEIGHT / 2) - 260);
  while (nb < 7000)
    {
      draw_black(explo);
      draw_gif(explo, &i, vector3f(vec.x, vec.y, GIF_18),
               vector2i(GIF_18_TOTAL, GIF_18_TIME));
      sfRenderWindow_display(explo->graph->window);
      nb++;
    }
}

void		stop_music_intro(t_explo *explo)
{
  sfMusic_stop(explo->music[SND_INC]);
  sfMusic_stop(explo->music[SND_EVACUATE]);
  sfMusic_stop(explo->music[SND_BFR_SIREN]);
  sfMusic_stop(explo->music[SND_DESTROY]);
  sfMusic_stop(explo->music[SND_SIREN]);
  sfMusic_stop(explo->music[SND_CRASH]);
}

void		intro(t_explo *explo)
{
  sfVector2f	pos;
  int		i;
  int		image;

  i = 0;
  image = 0;
  pos = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
		 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  while (1)
    {
      if ((get_event() == ESCAPE
	   && !wait_key(explo->graph->window, sfKeyEscape))
	  || image == GIF_15_TOTAL - 1)
	break;
      if (i == GIF_15_TIME)
	{
	  i = 0;
	  image++;
	}
      effect_intro(explo, image);
      draw_intro(explo, pos, image);
      i++;
    }
  stop_music_intro(explo);
  loading(explo);
}
