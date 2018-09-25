/*
** coal.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 18:55:07 2017 maxence.fourrier
** Last update Wed Oct 11 17:50:09 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2i	draw_fire(t_explo *explo, sfVector2i vec,
			  t_placed_mod *placed)
{
  int		x;
  int		y;

  x = vec.x;
  y = vec.y;
  draw_black(explo);
  if (placed->furnace.x)
    draw_gif(explo, &x, vector3f(293, 195, GIF_4),
	     vector2i(GIF_4_TOTAL, GIF_4_TIME));
  if (placed->furnace.y)
    draw_gif(explo, &y, vector3f(805, 195, GIF_4),
	     vector2i(GIF_4_TOTAL, GIF_4_TIME));
  return (vector2i(x, y));
}

void		draw_black(t_explo *explo)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2) - 45,
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_BLACK], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_BLACK], NULL);
}

int		click_coal(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	pos;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      pos = sfMouse_getPositionRenderWindow(explo->graph->window);
      if (change_furnace_on(pos, placed))
	return (1);
    }
  return (SUCCESS);
}

int		coal(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	fire;

  fire = vector2i(0, 50);
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      if (click_coal(explo, placed)
	  || click_add_coal(explo, placed))
	wait_mouse(explo->graph->window);
      explo->game->time = get_time();
      regen(explo);
      fire = draw_fire(explo, fire, placed);
      draw_coal(explo, placed);
      sfRenderWindow_display(explo->graph->window);
      music_coal(explo, placed);
    }
  play_stop_music(explo, vector2i(0, 0), vector2i(1, SND_COAL), 0);
  return (SUCCESS);
}
