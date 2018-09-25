/*
** draw_hud.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Sep 16 16:36:00 2017 maxence.fourrier
** Last update Sat Sep 23 16:00:22 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_hp(t_explo *explo)
{
  sfVector2i	pos;

  pos.y = 0;
  while (++pos.y < explo->player->hp * 2 && (pos.x = 4 * HUD_BAR_SIZE_X - 1))
    while (++pos.x < 5 * HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfRed);
  pos.y = 1 + HUD_BAR_SIZE_Y;
  while (--pos.y > explo->player->hp * 2 && (pos.x = 4 * HUD_BAR_SIZE_X - 1))
    while (++pos.x < 5 * HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfTransparent);
  sfTexture_updateFromPixels(explo->graph->texture,
			     explo->graph->framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		draw_power(t_explo *explo)
{
  sfVector2i	pos;

  pos.y = 0;
  while (++pos.y < explo->player->power * 2 && (pos.x = 2 * HUD_BAR_SIZE_X - 1))
    while (++pos.x < 3 * HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfYellow);
  pos.y = 1 + HUD_BAR_SIZE_Y;
  while (--pos.y > explo->player->power * 2 && (pos.x = 2 * HUD_BAR_SIZE_X - 1))
    while (++pos.x < 3 * HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfTransparent);
  sfTexture_updateFromPixels(explo->graph->texture,
			     explo->graph->framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		draw_oxygen(t_explo *explo)
{
  sfVector2i	pos;

  pos.y = 0;
  while (++pos.y < explo->player->oxy * 2 && (pos.x = -1))
    while (++pos.x < HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfBlue);
  pos.y = 1 + HUD_BAR_SIZE_Y;
  while (--pos.y > explo->player->oxy * 2 && (pos.x = -1))
    while (++pos.x < HUD_BAR_SIZE_X)
      my_put_pixel(explo->graph->framebuffer, pos.x, pos.y, sfTransparent);
  sfTexture_updateFromPixels(explo->graph->texture,
			     explo->graph->framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

void		draw_hud_bar(t_explo *explo)
{
  draw_hp(explo);
  draw_power(explo);
  draw_oxygen(explo);
}

void		draw_hud_sprite(t_explo *explo)
{
  int		i;

  i = 0;
  while (explo->hud[i])
    {
      sfSprite_setPosition(explo->hud[i],
			   vector2f(explo->player->pos.x + HUD_POS_X
				    + (28 * i) - 5,
				    explo->player->pos.y - 33 + HUD_POS_Y));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->hud[i], NULL);
      i++;
    }
}
