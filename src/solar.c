/*
** solar.c for tkadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 13:41:06 2017 maxence.fourrier
** Last update Wed Oct 11 18:54:53 2017 maxence.fourrier
*/

#include "explo.h"

int		check_clicked_pos_solar(t_explo *explo)
{
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  if (click.x >= 60 && click.x < 210 && click.y >= 150 && click.y < 300)
    return (1);
  if (click.x >= 60 && click.x < 210 && click.y >= 320 && click.y < 470)
    return (2);
  if (click.x >= 560 && click.x < 710 && click.y >= 490 && click.y < 640)
    return (3);
  return (SUCCESS);
}

int		link_solar_panel(t_explo *explo, t_placed_mod *solar,
				 int pos)
{
  if (pos == 2 && can_link(solar, explo))
    {
      del_inv(explo->player->inv, COPPER - '0' + 1, solar->link_cost);
      solar->link = 1;
      return (1);
    }
  return (SUCCESS);
}

int		upgrade_solar_panel(t_explo *explo,
				    t_placed_mod *solar, int pos)
{
  int		i;

  if (pos == 1 && can_upgrade(explo,
			      explo->game->upgrade[MODULE_SOLAR]
			      [solar->upgrade]))
    {
      i = -1;
      while (explo->game->upgrade[MODULE_SOLAR]
	     [solar->upgrade][++i] != -1)
	del_inv(explo->player->inv, i + 1,
		explo->game->upgrade[MODULE_SOLAR]
		[solar->upgrade][i]);
      solar->upgrade++;
      return (1);
    }
  return (SUCCESS);
}

int		check_clicked_solar(t_explo *explo,
				    t_placed_mod *solar)
{
  int		pos;
  int		i;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      pos = check_clicked_pos_solar(explo);
      if (upgrade_solar_panel(explo, solar, pos)
	  || link_solar_panel(explo, solar, pos))
	return (1);
      if (pos == 3 && solar->on == 1)
	{
	  solar->on = 0;
	  return (1);
	}
      if (pos == 3 && solar->on == 0)
	{
	  solar->on = 1;
	  return (1);
	}
    }
  return (SUCCESS);
}

int		solar(t_explo *explo, t_placed_mod *solar)
{
  int		i;

  i = 0;
  draw_solar(explo, solar);
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
	break;
      if (check_clicked_solar(explo, solar))
	wait_mouse(explo->graph->window);
      draw_solar(explo, solar);
      draw_gif(explo, &i, vector3f(1141, 500, GIF_1),
	       vector2i(GIF_1_TOTAL, GIF_1_TIME));
      sfRenderWindow_display(explo->graph->window);
      music_solar(explo, solar);
    }
  play_stop_music(explo, vector2i(0, 0),
		  vector2i(1, SND_SOLAR), 0);
  return (SUCCESS);
}
