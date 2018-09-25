/*
** fire_bird.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  9 17:17:42 2017 maxence.fourrier
** Last update Thu Oct 12 19:38:25 2017 maxence.fourrier
*/

#include "explo.h"

void		kill_mob(t_placed_mod *placed, t_mob *mob, t_explo *explo)
{
  effect_bird(explo);
  mob->type = -1;
  if (placed->inv[0][0]->item < 9)
    placed->inv[0][0]->item++;
  placed->inv[0][0]->quantity++;
}

void            draw_tower(t_explo *explo, t_placed_mod *placed,
                           int angle)
{
  sfSprite_setPosition(explo->gif[GIF_16][placed->link],
                       vector2f(placed->pos.x,
                                placed->pos.y));
  sfSprite_setOrigin(explo->gif[GIF_16][placed->link], vector2f(392, 92));
  sfSprite_setRotation(explo->gif[GIF_16][placed->link], angle);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[GIF_16][placed->link], NULL);
}

void		bird_not_in_range(t_explo *explo, t_placed_mod *placed)
{
  if (placed->link < 10)
    placed->link = GIF_16_TOTAL - 20;
  placed->furnace.x = 0;
  placed->upgrade++;
  if (placed->upgrade > GIF_16_TIME)
    {
      placed->upgrade = 0;
      placed->link++;
    }
  if (placed->link >= GIF_16_TOTAL)
    placed->link = GIF_16_TOTAL - 20;
  placed->angle += 0.1;
  draw_tower(explo, placed, placed->angle);
  sfSprite_setPosition(explo->gif[GIF_16][placed->link],
		       vector2f(placed->pos.x,
				placed->pos.y));
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->gif[GIF_16][placed->link], NULL);
}
