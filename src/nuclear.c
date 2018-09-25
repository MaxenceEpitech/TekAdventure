/*
** nuclear.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 29 15:13:38 2017 maxence.fourrier
** Last update Thu Oct 12 09:35:21 2017 maxence.fourrier
*/

#include "explo.h"

sfVector3f	nuclear_gif(t_explo *explo, sfVector3f vec,
			    t_placed_mod *placed)
{
  int		x;
  int		y;
  int		z;

  x = vec.x;
  y = vec.y;
  z = vec.z;
  if (placed->furnace.x)
    draw_gif(explo, &x, vector3f(180, 130, GIF_5),
	     vector2i(GIF_5_TOTAL, GIF_5_TIME));
  if (placed->furnace.y)
    draw_gif(explo, &y, vector3f(880, 130, GIF_5),
	     vector2i(GIF_5_TOTAL, GIF_5_TIME));
  draw_gif(explo, &z, vector3f(548, 380, GIF_6),
	   vector2i(GIF_6_TOTAL, GIF_6_TIME));
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}

int		click_add_nuclear(t_explo *explo, t_placed_mod *placed,
				  sfVector2i click)
{
  if (inv_contain(explo, URANIUM + 1 - '0') > 0
      && placed->inv[0][0]->quantity < 9
      && click.x >= 20 && click.x < 170
      && click.y >= 182 && click.y < 332)
    {
      placed->inv[0][0]->quantity++;
      del_inv(explo->player->inv, URANIUM - '0' + 1, 1);
    }
  if (inv_contain(explo, URANIUM + 1 - '0') > 0
      && placed->inv[0][1]->quantity < 9
      && click.x >= 1170 && click.x < 1320
      && click.y >= 182 && click.y < 332)
    {
      placed->inv[0][1]->quantity++;
      del_inv(explo->player->inv, URANIUM - '0' + 1, 1);
    }
  return (SUCCESS);
}

int		click_power_nuclear(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	click;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      change_nuclear_on(click, placed);
      click_add_nuclear(explo, placed, click);
      return (1);
    }
  return (SUCCESS);
}

int		nuclear(t_explo *explo, t_placed_mod *placed)
{
  sfVector3f	vec;

  vec = vector3f(0, 30, 0);
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      if (click_power_nuclear(explo, placed))
        wait_mouse(explo->graph->window);
      draw_black(explo);
      vec = nuclear_gif(explo, vec, placed);
      explo->game->time = get_time();
      regen(explo);
      draw_nuclear(explo, placed);
      sfRenderWindow_display(explo->graph->window);
      music_nuclear(explo, placed);
    }
  play_stop_music(explo, vector2i(0, 0), vector2i(1, SND_NUCLEAR), 0);
}
