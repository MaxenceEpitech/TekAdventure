/*
** draw_chest.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 11:28:11 2017 maxence.fourrier
** Last update Sun Oct  8 23:03:59 2017 jean-baptiste
*/

#include "explo.h"

void		draw_item_chest(t_explo *explo, int y, int x,
				t_placed_mod *placed)
{
  sfVector2f	vec;
  char		str[2];

  vec = vector2f(explo->player->pos.x + (x * (INV_DIM_X + 1))
                 + ITEM_DRAW_X,
                 explo->player->pos.y + (y * INV_DIM_Y)
                 + ITEM_DRAW_Y);
  sfSprite_setPosition(explo->item[placed->inv[y][x]->item],
                       vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[placed->inv
                                        [y][x]->item], NULL);
  vec.x += 100;
  vec.y += 65;
  sfText_setPosition(explo->graph->text, vec);
  str[0] = '0' + placed->inv[y][x]->quantity;
  str[1] = 0;
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
}

void		draw_chest_item(t_explo *explo, t_placed_mod *placed,
				sfVector2i draw)
{
  int		x;
  int		y;
  sfVector2f	vec;

  y = -1;
  while (placed->inv[++y] && (x = -1))
    while (placed->inv[y][++x])
      if (!(y == draw.y && x == draw.x))
	{
	  if (y == SIZE_INV_Y
	      && explo->player->inv[y][x]->item != -1)
	    draw_inv_equ(explo, x);
	  if (y != SIZE_INV_Y
	      && placed->inv[y][x]->item != -1)
	    draw_item_chest(explo, y, x, placed);
	}
}

void		draw_chest_trash(t_explo *explo, sfVector2f vec,
				 t_placed_mod *placed)
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
  if (pos.x != -1 && placed->inv[pos.y][pos.x]->item != -1)
    draw_name_item(explo, placed->inv[pos.y][pos.x]->item, click);
  else if (pos.x == -1)
    {
      pos = check_clicked_pos_equ(explo);
      if (pos.x != -1 && explo->player->inv[pos.y][pos.x]->item != -1)
	draw_name_item(explo, explo->player->inv[pos.y][pos.x]->item, click);
    }
}

void		draw_chest(t_explo *explo, t_placed_mod *placed,
			   sfVector2i draw, int *cpt)
{
  sfVector2f	vec;

  draw_black(explo);
  draw_gif(explo, cpt, vector3f(50, 10, GIF_11),
           vector2i(GIF_11_TOTAL, GIF_11_TIME));
  vec = vector2f(explo->player->pos.x + INV_DRAW_X,
                 explo->player->pos.y + INV_DRAW_Y);
  sfSprite_setPosition(explo->sprite[SPR_INV_CHEST],
		       vector2f(vec.x, vec.y - 53));
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_CHEST], NULL);
  vec = vector2f(explo->player->pos.x + EQU_DRAW_X,
		 explo->player->pos.y + EQU_DRAW_Y);
  sfSprite_setPosition(explo->sprite[SPR_INV_EQU], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_EQU], NULL);
  draw_chest_item(explo, placed, draw);
  draw_chest_trash(explo, vec, placed);
}
