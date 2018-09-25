/*
** fusion.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 16:38:22 2017 maxence.fourrier
** Last update Wed Oct 11 19:21:50 2017 maxence.fourrier
*/

#include "explo.h"

void		click_get_anti(t_explo *explo, t_placed_mod *placed,
			       sfVector2i click)
{
  sfVector2i	vec;

  if (click.x >= 1040 && click.x < 1190
      && click.y >= 400 && click.y < 550
      && placed->inv[0][0]->item > 0)
    {
      vec = inv_had_place_console(explo->player->inv, ANTI + 1 - '0');
      while (vec.x != -1 && placed->inv[0][0]->item > 0)
	{
	 add_item_inv_console(explo->player->inv, ANTI - '0' + 1, 1);
	 vec = inv_had_place_console(explo->player->inv, ANTI + 1 - '0');
	 placed->inv[0][0]->item--;
       }
    }
}

int		click_fusion(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	click;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      if (click.x >= 130 && click.x < 280
	  && click.y >= 280 && click.y < 430
	  && placed->furnace.x == 0
	  && explo->player->base_power >= FUSION_CONSO)
	placed->furnace.x = 1;
      else if (click.x >= 130 && click.x < 280
	  && click.y >= 280 && click.y < 430
	  && placed->furnace.x == 1)
	placed->furnace.x = 0;
      else
	click_get_anti(explo, placed, click);
      return (1);
    }
  return (SUCCESS);
}

sfVector3f	fusion_gif(t_explo *explo, sfVector3f vec,
			   t_placed_mod *placed)
{
  int		x;
  int		y;
  int		z;

  x = vec.x;
  y = vec.y;
  z = vec.z;
  draw_gif(explo, &x, vector3f(285, 141, GIF_8),
           vector2i(GIF_8_TOTAL, GIF_8_TIME));
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}

int		fusion(t_explo *explo, t_placed_mod *placed)
{
  sfVector3f	vec;

  if (placed->inv[0][0]->item == -1)
    placed->inv[0][0]->item = 0;
  vec = vector3f(0, 30, 0);
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      if (click_fusion(explo, placed))
        wait_mouse(explo->graph->window);
      vec = fusion_gif(explo, vec, placed);
      explo->game->time = get_time();
      regen(explo);
      draw_fusion(explo, placed);
      sfRenderWindow_display(explo->graph->window);
      music_fusion(explo, placed);
    }
  play_stop_music(explo, vector2i(0, 0), vector2i(1, SND_FUSION), 0);
  return (SUCCESS);
}
