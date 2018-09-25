/*
** draw_coal.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 18:55:54 2017 maxence.fourrier
** Last update Fri Sep 29 14:30:24 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_background_coal(t_explo *explo, t_placed_mod *placed,
				     sfVector2f vec)
{
  sfSprite_setPosition(explo->sprite[SPR_FURNACE], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_FURNACE], NULL);
}

void		draw_power_coal(t_explo *explo, t_placed_mod *placed,
				sfVector2f vec, sfVector2i pos)
{
  int		nb;

  if (placed->furnace.x == 0)
    nb = SPR_OFF;
  else
    nb = SPR_ON;
  if (pos.x >= 340 && pos.x < 505
      && pos.y >= 542 && pos.y < 692)
    nb++;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
  if (placed->furnace.y == 0)
    nb = SPR_OFF;
  else
    nb = SPR_ON;
  if (pos.x >= 855 && pos.x < 1020
      && pos.y >= 542 && pos.y < 692)
    nb++;
  vec.x += 515;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
}

void		draw_add_button_coal(t_explo *explo, int furnace,
				     sfVector2f vec, int sprite)
{
  int		nb;
  sfVector2i	click;

  if (inv_contain(explo, COAL - '0' + 1) > 0)
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      nb = SPR_ADD_G;
      if ((sprite == 1 && click.x >= 40 && click.x < 190
	   && click.y >= 412 && click.y < 562)
	  || (sprite == 2 && click.x >= 1140 && click.x < 1290
	      && click.y >= 412 && click.y < 562))
	nb++;
    }
  else
    nb = SPR_ADD_R;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
}

void		draw_amount_coal(t_explo *explo, sfVector2f vec,
				 t_inv *inv)
{
  char		*str;

  vec.y -= 200;
  vec.x += 20;
  sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_INV_G], NULL);
  vec.x += 5;
  sfSprite_setPosition(explo->item[COAL - '0' + 1], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[COAL - '0' + 1], NULL);
  str = my_int_to_str(inv->quantity);
  vec = vector2f(vec.x + 79, vec.y + 64);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
			  explo->graph->text, NULL);
}

void		draw_coal(t_explo *explo, t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	pos;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2) - 45,
		 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  draw_background_coal(explo, placed, vec);
  vec.x += 190;
  vec.y += 12;
  draw_level(explo, placed, vec);
  pos = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec.x += 195;
  vec.y += 530;
  draw_power_coal(explo, placed, vec, pos);
  vec.x -= 300;
  vec.y -= 130;
  draw_amount_coal(explo, vec, placed->inv[0][0]);
  draw_add_button_coal(explo, placed->furnace.x, vec, 1);
  vec.x += 1100;
  draw_amount_coal(explo, vec, placed->inv[0][1]);
  draw_add_button_coal(explo, placed->furnace.x, vec, 2);
}
