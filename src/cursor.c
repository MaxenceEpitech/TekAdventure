/*
** cursor.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 24 02:55:31 2017 maxence.fourrier
** Last update Sun Oct  8 10:56:52 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_cursor_text(t_explo *explo, sfVector2f click_map,
				 t_inv *inv)
{
  char		str[2];

  click_map.x += 100;
  click_map.y += 65;
  sfText_setPosition(explo->graph->text, click_map);
  str[0] = '0' + inv->quantity;
  str[1] = 0;
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
  sfRenderWindow_display(explo->graph->window);
}

void		draw_cursor(t_inv *inv, t_explo *explo,
			    sfVector2i pos, int *cpt)
{
  sfVector2i	click;
  sfVector2f	click_map;

  draw_inventory(explo, pos, cpt);
  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  click_map = sfRenderWindow_mapPixelToCoords(explo->graph->window,
                                              click, explo->graph->view);
  click_map.x -= INV_DIM_X / 2;
  click_map.y -= INV_DIM_Y / 2;
  sfSprite_setPosition(explo->item[inv->item],
		       click_map);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[inv->item], NULL);
  draw_cursor_text(explo, click_map, inv);
}

void		draw_chest_cursor(t_explo *explo, t_inv *inv)
{
  sfVector2f	vec;
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec = vector2f(explo->player->pos.x + click.x
		 - (SCREEN_WIDTH / 2) - 58,
		 explo->player->pos.y + click.y
		 - (SCREEN_HEIGHT / 2) - 58);
  sfSprite_setPosition(explo->item[inv->item], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[inv->item], NULL);
  draw_cursor_text(explo, vec, inv);
  sfRenderWindow_display(explo->graph->window);
}
