/*
** regen.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Sep 23 16:02:18 2017 maxence.fourrier
** Last update Fri Oct 13 13:33:02 2017 maxence.fourrier
*/

#include "explo.h"

void		regen_power_player(t_explo *explo)
{
  if (explo->player->power <= 95
      && explo->player->base_power >= 5)
    {
      explo->player->power += 5;
      explo->player->base_power -= 5;
    }
  else if (explo->player->power > 95
	   && explo->player->base_power > 0)
    {
      explo->player->base_power -= (explo->player->power - 100) * -1;
      explo->player->power = 100;
    }
}

void		regen_player(t_explo *explo)
{
  int		dist;

  if ((dist = get_dist_btw(vector2f(explo->game->base.x + 100,
				    explo->game->base.y + 120),
			   explo->player->pos)) < RADIUS_CIRCLE_HOME)
    {
      if (explo->player->oxy + REGEN_OXY < 100)
	explo->player->oxy += REGEN_OXY;
      else
	explo->player->oxy = 100;
      regen_power_player(explo);
      explo->game->regen_player = explo->game->time;
      draw_hud_bar(explo);
    }
}

void		conso_oxy(t_explo *explo)
{
  if (explo->player->oxy > 0)
    {
      if (get_dist_btw(vector2f(explo->game->base.x + 100,
				explo->game->base.y + 120),
		       explo->player->pos) > RADIUS_CIRCLE_HOME)
	{
	  explo->player->oxy--;
	  explo->game->conso_oxy = explo->game->time;
	  draw_hud_bar(explo);
	}
    }
  else
    {
      effect_dmg(explo);
      explo->player->hp--;
      explo->game->conso_oxy = explo->game->time;
      draw_hud_bar(explo);
    }
}

int		regen(t_explo *explo)
{
  if (explo->game->time > explo->game->regen_player
      + (REGEN_TIME_PLAYER * explo->config->difficulty))
    regen_player(explo);
  if (explo->game->time > explo->game->regen_base
      + (REGEN_TIME_BASE * explo->config->difficulty))
    {
      explo->player->base_power += get_prod_base(explo, explo->game->placed);
      explo->game->regen_base = explo->game->time;
      check_conso_module(explo, explo->game->placed);
      do_storm(explo);
    }
  if (explo->game->time > explo->game->conso_oxy
      + (CONSO_TIME_OXY * explo->config->difficulty))
    conso_oxy(explo);
  if (explo->game->time > explo->game->spawn_mob + 5 * 1000)
    gen_mob(explo);
}
