/*
** mine_time.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 19:08:41 2017 maxence.fourrier
** Last update Thu Oct 12 18:58:09 2017 maxence.fourrier
*/

#include <sys/time.h>
#include "explo.h"

void			draw_effect_mine(t_explo *explo, int draw_,
					 sfVector2f pos)
{
  sfVector2i		vec;
  int			spr;

  if (draw_ < 333)
    spr = SPR_MINE_1;
  else if (draw_ >= 333 && draw_ <= 666)
    spr = SPR_MINE_2;
  else if (draw_ > 666)
    spr = SPR_MINE_3;
  vec = vector2i(pos.x / SPRITE_FLOOR_SIZE,
                 pos.y / SPRITE_FLOOR_SIZE);
  pos = vector2f(vec.x * SPRITE_FLOOR_SIZE,
                 vec.y * SPRITE_FLOOR_SIZE);
  sfSprite_setPosition(explo->sprite[spr], pos);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[spr], NULL);
}

void			draw_while_mining(t_explo *explo, int draw_,
					  sfVector2f click_map)
{
  if (explo->game->draw_time + 5 <= explo->game->time)
    {
      explo->game->draw_time = get_time();
      move(explo);
      sfRenderWindow_setView(explo->graph->window, explo->graph->view);
      regen(explo);
      draw_floor(explo);
      draw_effect_mine(explo, draw_, click_map);
      draw_rest(explo);
      sfSprite_setPosition(explo->graph->sprite,
                           vector2f(explo->player->pos.x + HUD_POS_X,
                                    explo->player->pos.y + HUD_POS_Y));
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->graph->sprite, NULL);
      storm(explo);
      sfRenderWindow_display(explo->graph->window);
    }
}

int			mouse_pressed_mine(t_explo *explo,
					   sfVector2i click,
					   int draw_)
{
  sfVector2i		mouse;
  sfVector2f		click_map;

  mouse = sfMouse_getPositionRenderWindow(explo->graph->window);
  click_map = sfRenderWindow_mapPixelToCoords(explo->graph->window,
                                              mouse, explo->graph->view);
  if ((int)(click_map.x / SPRITE_FLOOR_SIZE) != click.x
      || (int)(click_map.y / SPRITE_FLOOR_SIZE) != click.y)
    return (1);
  draw_while_mining(explo, draw_, click_map);
  return (SUCCESS);
}

int			check_mine_time(sfVector2i click, t_explo *explo)
{
  unsigned long long	start;
  unsigned long long	end;
  int			draw;

  start = get_time();
  end = get_time();
  while (sfMouse_isButtonPressed(sfMouseRight)
         && end < start + 1000)
    {
      effect_drill(explo);
      draw = end - start;
      explo->game->time = get_time();
      if (mouse_pressed_mine(explo, click, draw))
        return (SUCCESS);
      end = get_time();
    }
  if (end < start + 1000)
    return (SUCCESS);
  return (1);
}
