/*
** draw_solar_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 20:58:15 2017 maxence.fourrier
** Last update Sun Oct  8 11:00:36 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_arrow_solar_upg(t_explo *explo, t_inv ***inv,
				     t_placed_mod *placed)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2) + 250,
                 explo->player->pos.y - (SCREEN_HEIGHT / 2) + 193);
  if (can_upgrade(explo, explo->game->upgrade[MODULE_SOLAR][placed->upgrade]))
    {
      sfSprite_setPosition(explo->sprite[SPR_ARROW_G], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_ARROW_G], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_ARROW_R], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_ARROW_R], NULL);
    }
}

void		draw_arrow_solar_link(t_explo *explo, t_inv ***inv,
				      t_placed_mod *placed)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2) + 250,
                 explo->player->pos.y - (SCREEN_HEIGHT / 2) + 350);
  if (can_link(explo->game->placed, explo))
    {
      sfSprite_setPosition(explo->sprite[SPR_ARROW_G], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_ARROW_G], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_ARROW_R], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_ARROW_R], NULL);
    }
}

void		draw_produc(t_explo *explo, t_placed_mod *placed,
			    sfVector2f vec)
{
  char		*str;

  vec.x += 400;
  vec.y -= 15;
  sfSprite_setPosition(explo->sprite[SPR_SPEED], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_SPEED], NULL);
  str = my_int_to_str(get_prod_module(explo, placed));
  str = new_cat(str, PER_SECOND);
  vec.x += 180;
  vec.y += 15;
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_level(t_explo *explo, t_placed_mod *placed,
			   sfVector2f vec)
{
  char		*str;

  sfSprite_setPosition(explo->sprite[SPR_LEVEL], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_LEVEL], NULL);
  sfText_setCharacterSize(explo->graph->text, 90);
  str = new_cat(LEVEL, my_int_to_str(placed->upgrade + 1));
  vec.x += 150;
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
			  explo->graph->text, NULL);
  draw_produc(explo, placed, vec);
  sfText_setCharacterSize(explo->graph->text, 50);
}
