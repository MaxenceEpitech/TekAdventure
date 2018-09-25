/*
** draw_inventory.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep  8 17:25:04 2017 maxence.fourrier
** Last update Sun Oct  8 11:00:05 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_inv_equ(t_explo *explo, int x)
{
  sfVector2f	vec;
  char		str[2];

  vec = vector2f(explo->player->pos.x + (x * (INV_DIM_X + 1))
		 + EQU_DRAW_X + 34,
		 explo->player->pos.y
		 + EQU_DRAW_Y + 35);
  sfSprite_setPosition(explo->item[explo->player->inv[SIZE_INV_Y][x]->item],
		       vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[explo->player->inv
					[SIZE_INV_Y][x]->item], NULL);
  vec.x += 100;
  vec.y += 65;
  sfText_setPosition(explo->graph->text, vec);
  str[0] = '0' + explo->player->inv[SIZE_INV_Y][x]->quantity;
  str[1] = 0;
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_inv_top(t_explo *explo, int y, int x)
{
  sfVector2f	vec;
  char		str[2];

  vec = vector2f(explo->player->pos.x + (x * (INV_DIM_X + 1))
		 + ITEM_DRAW_X,
		 explo->player->pos.y + (y * INV_DIM_Y)
		 + ITEM_DRAW_Y);
  sfSprite_setPosition(explo->item[explo->player->inv[y][x]->item],
		       vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[explo->player->inv
					[y][x]->item], NULL);
  vec.x += 100;
  vec.y += 65;
  sfText_setPosition(explo->graph->text, vec);
  str[0] = '0' + explo->player->inv[y][x]->quantity;
  str[1] = 0;
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_item_inv(t_explo *explo, sfVector2i pos)
{
  int		x;
  int		y;
  sfVector2f	vec;

  y = -1;
  while (explo->player->inv[++y] && (x = -1))
    while (explo->player->inv[y][++x])
      if (explo->player->inv[y][x]->item != -1
	  && !(y == pos.y && x == pos.x))
	{
	  if (y == SIZE_INV_Y)
	    draw_inv_equ(explo, x);
	  else
	    draw_inv_top(explo, y, x);
	}
}

void		draw_trash(t_explo *explo, sfVector2f vec)
{
  sfVector2i	click;
  sfVector2i	pos;

  vec.x -= 170;
  vec.y += 45;
  sfSprite_setPosition(explo->sprite[SPR_TRASH], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_TRASH], NULL);
  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  pos = check_clicked_pos(explo);
  if (pos.x == -1)
    pos = check_clicked_pos_equ(explo);
  if (pos.x != -1 && explo->player->inv[pos.y][pos.x]->item != -1)
    draw_name_item(explo, explo->player->inv[pos.y][pos.x]->item, click);
}

void		draw_inventory(t_explo *explo, sfVector2i pos, int *cpt)
{
  sfVector2f	vec;

  draw_black(explo);
  vec = vector2f(explo->player->pos.x + INV_DRAW_X,
		 explo->player->pos.y + INV_DRAW_Y);
  sfSprite_setPosition(explo->sprite[SPR_INV], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_INV], NULL);
  vec = vector2f(explo->player->pos.x + EQU_DRAW_X,
		 explo->player->pos.y + EQU_DRAW_Y);
  sfSprite_setPosition(explo->sprite[SPR_INV_EQU], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_INV_EQU], NULL);
  draw_item_inv(explo, pos);
  draw_trash(explo, vec);
  draw_gif(explo, cpt, vector3f(50, 10, GIF_11),
	   vector2i(GIF_11_TOTAL, GIF_11_TIME));
}
