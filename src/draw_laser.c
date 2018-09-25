/*
** draw_laser.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src/maxence
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 16:43:53 2017 maxence.fourrier
** Last update Mon Oct  9 18:59:52 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_item_laser(t_explo *explo, t_placed_mod *placed,
				sfVector2f vec)
{
  char		*str;

  vec.x += 640;
  vec.y += 290;
  sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_G], NULL);
  vec.x += 7;
  vec.y += 10;
  sfSprite_setPosition(explo->item[FOOD - '0' + 1], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[FOOD - '0' + 1], NULL);
  str = my_int_to_str(placed->inv[0][0]->item);
  vec = vector2f(vec.x + 95, vec.y + 63);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
}

void		draw_take_laser(t_explo *explo, t_placed_mod *placed,
				sfVector2f vec, sfVector2i click)
{
  vec.x += 630;
  vec.y += 400;
  if (click.x >= 630 && click.x < 790
      && click.y >= 430 && click.y < 520)
    {
      sfSprite_setPosition(explo->sprite[SPR_TAKE_],
			   vector2f(vec.x + 5, vec.y + 5));
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_TAKE_], NULL);
      click_laser(explo, placed);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_TAKE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
                                explo->sprite[SPR_TAKE], NULL);
    }
}

void		draw_kill_laser(t_explo *explo, t_placed_mod *placed,
				sfVector2f vec)
{
  char		*str;

  str = my_int_to_str(placed->inv[0][0]->quantity);
  str = new_cat(str, " : Enemy slain.");
  sfText_setPosition(explo->graph->text, vector2f(vec.x + 450,
						  vec.y + 50));
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
}

void		draw_laser(t_explo *explo, t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	click;

  sfText_setCharacterSize(explo->graph->text, 90);
  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_LASER_T], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_LASER_T], NULL);
  draw_kill_laser(explo, placed, vec);
  sfText_setCharacterSize(explo->graph->text, 50);
  draw_item_laser(explo, placed, vec);
  draw_take_laser(explo, placed, vec, click);
}
