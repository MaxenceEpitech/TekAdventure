/*
** draw_base.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 13:00:01 2017 maxence.fourrier
** Last update Thu Sep 28 10:40:45 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_base_production(t_explo *explo, sfVector2f vec)
{
  char		*str;

  sfSprite_setPosition(explo->sprite[SPR_SPEED], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_SPEED], NULL);
  str = my_int_to_str(get_prod_base(explo, explo->game->placed));
  str = new_cat(str, PER_SECOND);
  vec.x += 250;
  vec.y += 30;
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_base_energy(t_explo *explo, sfVector2f vec)
{
  char		*str;

  vec.y += 25;
  vec.x -= 5;
  sfSprite_setPosition(explo->sprite[SPR_BATTERY], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_BATTERY], NULL);
  str = my_int_to_str(explo->player->base_power);
  if (explo->player->base_power <= 1)
    str = new_cat(str, TOTAL_ENERGY);
  else
    str = new_cat(str, TOTALS_ENERGY);
  vec.x += 255;
  vec.y += 5;
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_base_amount(t_explo *explo, sfVector2f vec,
				 t_placed_mod *placed)
{
  char		*str;
  int		i;

  i = -1;
  while (placed != NULL)
    {
      placed = placed->next;
      i++;
    }
  vec.x -= 30;
  sfSprite_setPosition(explo->sprite[SPR_AMOUNT], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_AMOUNT], NULL);
  if (i <= 1)
    str = new_cat(my_int_to_str(i), MODULE_PLACED);
  else
    str = new_cat(my_int_to_str(i), MODULES_PLACED);
  vec.x += 280;
  vec.y += 30;
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_base_upgrade(t_explo *explo, sfVector2f vec)
{
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  if (click.x >= 80 && click.x < 230
      && click.y >= 470 && click.y < 620)
    {
      sfSprite_setPosition(explo->sprite[SPR_UPGRADE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_UPGRADE], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_UPGRADE_], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_UPGRADE_], NULL);
    }
}

void		draw_base(t_explo *explo)
{
  sfVector2f	vec;
  t_placed_mod	*placed;

  sfText_setCharacterSize(explo->graph->text, 90);
  vec.x = explo->player->pos.x - (SCREEN_WIDTH / 2) + 80;
  vec.y = explo->player->pos.y - (SCREEN_HEIGHT / 2) + 10;
  draw_base_production(explo, vec);
  vec.y += 130;
  draw_base_amount(explo, vec, explo->game->placed);
  vec.y += 130;
  draw_base_energy(explo, vec);
  vec.y += 200;
  draw_base_upgrade(explo, vec);
  sfText_setCharacterSize(explo->graph->text, 50);
  vec.x += 200;
  placed = get_base_module(explo->game->placed);
  draw_upgrade(explo, explo->game->upgrade[MODULE_BASE]
	       [placed->upgrade], vec, placed);
}
