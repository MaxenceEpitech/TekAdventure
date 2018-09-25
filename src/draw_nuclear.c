/*
** draw_nuclear.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 29 15:17:28 2017 maxence.fourrier
** Last update Fri Sep 29 21:07:13 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_power_nuclear(t_explo *explo, t_placed_mod *placed,
				   sfVector2f vec, sfVector2i pos)
{
  int		nb;

  if (placed->furnace.x == 0)
    nb = SPR_OFF;
  else
    nb = SPR_ON;
  if (pos.x >= 480 && pos.x < 630
      && pos.y >= 182 && pos.y < 332)
    nb++;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
  if (placed->furnace.y == 0)
    nb = SPR_OFF;
  else
    nb = SPR_ON;
  if (pos.x >= 710 && pos.x < 860
      && pos.y >= 182 && pos.y < 332)
    nb++;
  vec.x += 230;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
}

void		draw_add_nuclear(t_explo *explo, t_placed_mod *placed,
				 sfVector2f vec, int sprite)
{
  int		nb;
  sfVector2i	click;

  if (inv_contain(explo, URANIUM - '0' + 1) > 0)
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      nb = SPR_ADD_G;
      if ((sprite == 1 && click.x >= 20 && click.x < 170
           && click.y >= 182 && click.y < 332)
          || (sprite == 2 && click.x >= 1170 && click.x < 1320
              && click.y >= 182 && click.y < 332))
        nb++;
    }
  else
    nb = SPR_ADD_R;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);

}

void		draw_amount_nuclear(t_explo *explo, sfVector2f vec,
				    t_inv *inv)
{
  char		*str;

  vec.y += 250;
  sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_G], NULL);
  vec.x += 7;
  vec.y += 10;
  sfSprite_setPosition(explo->item[URANIUM - '0' + 1], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[URANIUM - '0' + 1], NULL);
  str = my_int_to_str(inv->quantity);
  vec = vector2f(vec.x + 95, vec.y + 63);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
}

void		draw_nuclear(t_explo *explo, t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	click;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_NUCLEAR_REAC], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_NUCLEAR_REAC], NULL);
  vec.x += 100;
  vec.y += 12;
  draw_level(explo, placed, vec);
  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec.x += 380;
  vec.y += 170;
  draw_power_nuclear(explo, placed, vec, click);
  vec.x -= 460;
  draw_add_nuclear(explo, placed, vec, 1);
  draw_amount_nuclear(explo, vec, placed->inv[0][0]);
  vec.x += 1150;
  draw_add_nuclear(explo, placed, vec, 2);
  draw_amount_nuclear(explo, vec, placed->inv[0][1]);
}
