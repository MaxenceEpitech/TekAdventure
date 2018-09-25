/*
** draw_upgrade.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 19:33:41 2017 maxence.fourrier
** Last update Fri Oct  6 19:53:27 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_arrow_upgrade(t_explo *explo, int *upgrade,
				   sfVector2f vec, t_placed_mod *placed)
{
  vec.y += 25;
  if (can_upgrade(explo, explo->game->upgrade[MODULE_BASE]
		  [placed->upgrade]))
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

void		draw_frame_upgrade(t_explo *explo, sfVector2f vec,
				   int item, int ammount)
{
  if ((inv_contain(explo, item) >= ammount))
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
}

void		draw_item_number(t_explo *explo, sfVector2f vec,
				 int ammount, int item)
{
  char		*str;

  vec = vector2f(vec.x + 9, vec.y + 9);
  sfSprite_setPosition(explo->item[item], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->item[item], NULL);
  str = my_int_to_str(ammount);
  if (str[1] != 0)
    {
      vec = vector2f(vec.x + 79, vec.y + 64);
      sfText_setPosition(explo->graph->text, vec);
      sfText_setString(explo->graph->text, str);
      sfRenderWindow_drawText(explo->graph->window,
                              explo->graph->text, NULL);
    }
  else
    {
      vec = vector2f(vec.x + 100, vec.y + 64);
      sfText_setPosition(explo->graph->text, vec);
      sfText_setString(explo->graph->text, str);
      sfRenderWindow_drawText(explo->graph->window,
                              explo->graph->text, NULL);
    }
  free(str);
}

void		draw_item_upgrade(t_explo *explo, int *upgrade,
				  sfVector2f vec, t_placed_mod *placed)
{
  int		i;

  i = -1;
  while (explo->game->upgrade[placed->type]
	 [placed->upgrade][++i] != -1)
    if (explo->game->upgrade[placed->type][placed->upgrade][i] > 0)
      {
	draw_frame_upgrade(explo, vec, i + 1,
			   explo->game->upgrade[placed->type]
			   [placed->upgrade][i]);
	draw_item_number(explo, vec,
			 explo->game->upgrade[placed->type]
			 [placed->upgrade][i], i + 1);
	vec.x += 140;
      }
}

void		draw_upgrade(t_explo *explo, int *upgrade,
			     sfVector2f vec, t_placed_mod *placed)
{
  if (upgrade == NULL)
    {
      vec.y -= 30;
      sfSprite_setPosition(explo->sprite[SPR_DONE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_DONE], NULL);
    }
  else
    {
      draw_arrow_upgrade(explo, upgrade, vec, placed);
      vec.x += 120;
      draw_item_upgrade(explo, upgrade, vec, placed);
    }
}
