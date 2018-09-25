/*
** launcher.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  1 13:49:48 2017 maxence.fourrier
** Last update Sun Oct  8 19:40:27 2017 maxence.fourrier
*/

#include "explo.h"

sfVector3f	draw_launcher_back(t_explo *explo, sfVector3f vec)
{
  int		save;
  int		x;
  int		y;
  int		z;

  x = vec.x;
  y = vec.y;
  z = vec.z;
  draw_black(explo);
  draw_gif(explo, &x, vector3f(-20, -100, GIF_2),
           vector2i(GIF_2_TOTAL, GIF_2_TIME));
  x = vec.x;
  draw_gif(explo, &x, vector3f(750, 380, GIF_2),
           vector2i(GIF_2_TOTAL, GIF_2_TIME));
  draw_gif(explo, &y, vector3f(-20, 330, GIF_2),
           vector2i(GIF_2_TOTAL, GIF_2_TIME));
  draw_gif(explo, &z, vector3f(670, -110, GIF_7),
           vector2i(GIF_7_TOTAL, GIF_7_TIME));
  return (vector3f(x, y, z));
}

void		add_item_inv_launcher(t_inv *inv, t_explo *explo)
{
  if (inv_contain(explo, ANTI - '0' + 1) > 0
      && inv->quantity == 0)
    {
      del_inv(explo->player->inv, ANTI - '0' + 1, 1);
      inv->quantity++;
    }
}

int		click_launcher(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	click;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      if (click.x >= 80 && click.x < 230
	  && click.y >= 40 && click.y < 190)
	add_item_inv_launcher(placed->inv[0][0], explo);
      if (click.x >= 1030 && click.x < 1180
	  && click.y >= 490 && click.y < 640)
	add_item_inv_launcher(placed->inv[0][1], explo);
      if (click.x >= 80 && click.x < 230
	  && click.y >= 510 && click.y < 660)
	add_item_inv_launcher(placed->inv[0][2], explo);
      if (click.x >= 0 && click.x < 200
	  && click.y >= 0 && click.y < 200
	  && placed->inv[0][0]->quantity == 1
	  && placed->inv[0][1]->quantity == 1
	  && placed->inv[0][2]->quantity == 1)
	return (2);
      return (1);
    }
  return (SUCCESS);
}

int		launcher(t_explo *explo, t_placed_mod *placed)
{
  sfVector3f	vec;
  int		ret;

  vec = vector3f(0, 0, 0);
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      if ((ret = click_launcher(explo, placed)))
	wait_mouse(explo->graph->window);
      if (ret == 2)
	return (1);
      explo->game->time = get_time();
      regen(explo);
      vec = draw_launcher_back(explo, vec);
      draw_launcher(explo, placed);
      sfRenderWindow_display(explo->graph->window);
    }
  return (SUCCESS);
}
