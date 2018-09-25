/*
** draw.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep  5 18:58:05 2017 maxence.fourrier
** Last update Mon Oct  9 19:18:31 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_floor(t_explo *explo)
{
  init_placed_draw(explo->game->placed);
  draw_map(explo);
}

void		draw_rest(t_explo *explo)
{
  draw_home(explo);
  draw_env(explo);
  draw_egg_before(explo);
  draw_placed(explo, explo->game->placed, explo->player->pos);
  draw_click(explo);
  draw_perso(explo);
  draw_env_after_player(explo, explo->game->rock);
  draw_egg_after(explo);
  draw_undraw_placed(explo, explo->game->placed);
  draw_bird(explo);
  draw_game_time(explo);
  draw_hud_sprite(explo);
}

void		draw_all(t_explo *explo)
{
  draw_floor(explo);
  draw_rest(explo);
}

void		draw(t_explo *explo)
{
  if (explo->game->draw_time + 5 <= explo->game->time)
    {
      explo->game->draw_time = get_time();
      move(explo);
      sfRenderWindow_setView(explo->graph->window, explo->graph->view);
      draw_all(explo);
      sfSprite_setPosition(explo->graph->sprite,
			   vector2f(explo->player->pos.x + HUD_POS_X,
				    explo->player->pos.y + HUD_POS_Y));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->graph->sprite, NULL);
      storm(explo);
      sfRenderWindow_display(explo->graph->window);
    }
}
