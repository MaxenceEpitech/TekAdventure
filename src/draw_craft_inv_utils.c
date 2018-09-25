/*
** draw_craft_inv_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 20 00:00:27 2017 maxence.fourrier
** Last update Sun Oct  8 23:12:20 2017 jean-baptiste
*/

#include "explo.h"

int		draw_item_craft(t_explo *explo, int i, int page)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x + INV_CRAFT_X - 50,
                 explo->player->pos.y
		 + ((i - (page * SIZE_OF_PAGE))
		    * INV_CRAFT_Y)
                 + (((i - (page * SIZE_OF_PAGE)) - 1)
		    * SIZE_CRAFT_Y));
  sfSprite_setPosition(explo->item[i + 19], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[i + 19], NULL);
}

int		is_craftable(t_explo *explo, int i)
{
  sfVector2i	pos;
  int		x;

  x = 0;
  while (explo->game->module[i]->quantity[x] != -1)
    {
      if (explo->game->module[i]->quantity[x]
	  > inv_contain(explo, x))
	return (SUCCESS);
      x++;
    }
  pos = inv_has_place(explo, i);
  if (pos.x == -1)
    return (SUCCESS);
  return (1);
}

int		draw_arrow(t_explo *explo, int i, int page)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x + (2 * INV_CRAFT_X),
                 explo->player->pos.y
		 + ((i - (page * SIZE_OF_PAGE))
		    * INV_CRAFT_Y + CRAFT_CROSS)
                 + (((i - (page * SIZE_OF_PAGE)) - 1)
		    * SIZE_CRAFT_Y));
  if (is_craftable(explo, i))
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
