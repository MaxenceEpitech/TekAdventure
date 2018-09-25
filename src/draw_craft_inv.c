/*
** draw_craft_inv.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 19 09:55:38 2017 maxence.fourrier
** Last update Thu Oct  5 19:35:34 2017 maxence.fourrier
*/

#include "explo.h"

int		draw_frame(t_explo *explo, int i,
			   int x, sfVector2f vec)
{
  vec.x -= 5;
  vec.y -= 5;
  if (inv_contain(explo, x) >=
      explo->game->module[i]->quantity[x])
    {
      sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_INV_G], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_INV_R], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_INV_R], NULL);
    }
  return (SUCCESS);
}

int		draw_needed_ammount(t_explo *explo, int i,
				    int x, sfVector2f vec)
{
  char		*str;

  draw_frame(explo, i, x, vec);
  sfSprite_setPosition(explo->item[x], vec);
  sfRenderWindow_drawSprite(explo->graph->window, explo->item[x], NULL);
  str = my_int_to_str(explo->game->module[i]->quantity[x]);
  if (str[1] != 0)
    {
      vec = vector2f(vec.x + 85, vec.y + 65);
      sfText_setPosition(explo->graph->text, vec);
      sfText_setString(explo->graph->text, str);
      sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
    }
  else
    {
      vec = vector2f(vec.x + 100, vec.y + 65);
      sfText_setPosition(explo->graph->text, vec);
      sfText_setString(explo->graph->text, str);
      sfRenderWindow_drawText(explo->graph->window, explo->graph->text, NULL);
    }
  free(str);
}

int		draw_needed_item(t_explo *explo, int i, int page)
{
  int		x;
  sfVector2f	vec;

  x = 0;
  vec = vector2f(explo->player->pos.x + (3 * INV_CRAFT_X),
                 explo->player->pos.y
		 + ((i - (page * SIZE_OF_PAGE)) * INV_CRAFT_Y)
                 + (((i - (page * SIZE_OF_PAGE)) - 1)
		    * SIZE_CRAFT_Y));
  while (explo->game->module[i]->quantity[x] != -1)
    {
      if (explo->game->module[i]->quantity[x] > 0)
	{
	  draw_needed_ammount(explo, i, x, vec);
	  vec.x += SIZE_CRAFT_X;
	}
      x++;
    }
  return (SUCCESS);
}

void		draw_craft_inv(t_explo *explo, int page)
{
  sfVector2f	vec;
  int		i;

  i = (1 + (SIZE_OF_PAGE * page));
  draw_all(explo);
  draw_hud_bar(explo);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->graph->sprite, NULL);
  while (explo->game->module[i] &&
	 i < 1 + SIZE_OF_PAGE + (SIZE_OF_PAGE * page))
    {
      vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
		     explo->player->pos.y - (SCREEN_HEIGHT / 2));
      draw_arrow(explo, i, page);
      draw_item_craft(explo, i, page);
      draw_needed_item(explo, i, page);
      i++;
    }
  sfRenderWindow_display(explo->graph->window);
}
