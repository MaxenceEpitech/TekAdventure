/*
** draw_fusion.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 16:39:07 2017 maxence.fourrier
** Last update Tue Oct  3 00:35:36 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_power_fusion(t_explo *explo, t_placed_mod *placed,
				  sfVector2i click, sfVector2f vec)
{
  int		nb;

  if (placed->furnace.x == 0)
    nb = SPR_OFF;
  else
    nb = SPR_ON;
  if (click.x >= 130 && click.x < 280
      && click.y >= 280 && click.y < 430)
    nb++;
  vec.x += 130;
  vec.y += 280;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
}

void		draw_percent_fusion(t_explo *explo, t_placed_mod *placed,
				    sfVector2f vec)
{
  char		*str;

  str = my_int_to_str(placed->inv[0][0]->quantity);
  str = new_cat("Current :  ", str);
  str = new_cat(str, "  %");
  sfText_setPosition(explo->graph->text, vector2f(vec.x + 500, vec.y));
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
  sfSprite_setPosition(explo->sprite[SPR_SPEED],
		       vector2f(vec.x + 120, vec.y + 560));
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_SPEED], NULL);
  str = my_int_to_str(FUSION_CONSO);
  str = new_cat("Consumption : ", str);
  str = new_cat(str, CONSO_FUSION_);
  sfText_setPosition(explo->graph->text, vector2f(vec.x + 290, vec.y + 600));
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);

}

void		draw_prod_fusion(t_explo *explo, t_placed_mod *placed,
				 sfVector2i click, sfVector2f vec)
{
  char		*str;

  vec.x += 1050;
  vec.y += 290;
  sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_G], NULL);
  vec.x += 7;
  vec.y += 10;
  sfSprite_setPosition(explo->item[ANTI - '0' + 1], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[ANTI - '0' + 1], NULL);
  str = my_int_to_str(placed->inv[0][0]->item);
  vec = vector2f(vec.x + 95, vec.y + 63);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
}

void		draw_take(t_explo *explo, sfVector2f vec,
			  sfVector2i click)
{
  vec.x += 1040;
  vec.y += 400;
  if (click.x >= 1040 && click.x < 1190
      && click.y >= 400 && click.y < 550)
    {
      vec.x += 5;
      vec.y += 5;
      sfSprite_setPosition(explo->sprite[SPR_TAKE_], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_TAKE_], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_TAKE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_TAKE], NULL);
    }
}

void		draw_fusion(t_explo *explo, t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_FUSION_B], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_FUSION_B], NULL);
  draw_power_fusion(explo, placed, click, vec);
  draw_prod_fusion(explo, placed, click, vec);
  sfText_setCharacterSize(explo->graph->text, 90);
  draw_percent_fusion(explo, placed, vec);
  draw_take(explo, vec, click);
  sfText_setCharacterSize(explo->graph->text, 50);
}
