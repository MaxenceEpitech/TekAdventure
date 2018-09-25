/*
** draw_solar.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 16:31:21 2017 maxence.fourrier
** Last update Thu Sep 28 10:06:48 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_done(t_explo *explo, sfVector2f pos)
{
  pos.x += explo->player->pos.x - (SCREEN_WIDTH / 2);
  pos.y += explo->player->pos.y - (SCREEN_HEIGHT / 2);
  sfSprite_setPosition(explo->sprite[SPR_DONE], pos);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_DONE], NULL);
}

void		draw_needed_upgrade(t_explo *explo, t_placed_mod *solar)
{
  int		i;
  sfVector2f	vec;

  i = 0;
  vec = vector2f(explo->player->pos.x + 370 - (SCREEN_WIDTH / 2),
		 explo->player->pos.y + 168 - (SCREEN_HEIGHT / 2));
  while (explo->game->upgrade[solar->type][solar->upgrade][i] != -1)
    {
      if (explo->game->upgrade[solar->type][solar->upgrade][i] > 0)
	{
	  draw_frame_upgrade(explo, vec, i + 1,
			     explo->game->upgrade[solar->type]
			     [solar->upgrade][i]);
	  draw_item_number(explo, vec,
			   explo->game->upgrade[solar->type]
			   [solar->upgrade][i], i + 1);
	  vec.x += 140;
	}
      i++;
    }
}

void		draw_needed_link(t_explo *explo, int nb)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x + 370 - (SCREEN_WIDTH / 2),
		 explo->player->pos.y + 327 - (SCREEN_HEIGHT / 2));
  draw_frame_upgrade(explo, vec, COPPER - '0' + 1, nb);
  draw_item_number(explo, vec,
		   nb , COPPER - '0' + 1);
}

void		draw_solar(t_explo *explo, t_placed_mod *solar)
{
  int		x;

  draw_button(explo, vector2i(SPR_UPGRADE, SPR_UPGRADE_),
	      vector2i(SPR_LINK, SPR_LINK_), solar);
  draw_level(explo, solar, vector2f(explo->player->pos.x + 90
				    - (SCREEN_WIDTH / 2),
				    explo->player->pos.y + 12
				    - (SCREEN_HEIGHT / 2)));
  if (explo->game->upgrade[MODULE_SOLAR][solar->upgrade] != NULL)
    {
      draw_arrow_solar_upg(explo, explo->player->inv, solar);
      draw_needed_upgrade(explo, solar);
    }
  else
    draw_done(explo, vector2f(230, 130));
  if (solar->link != 1)
    {
      draw_arrow_solar_link(explo, explo->player->inv, solar);
      draw_needed_link(explo, solar->link_cost);
    }
  else
    draw_done(explo, vector2f(230, 300));
}
