/*
** death.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 13 10:39:11 2017 maxence.fourrier
** Last update Fri Oct 13 13:05:32 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_death(t_explo *explo, unsigned long long start,
			   unsigned long long current)
{
  sfVector2f	vec;
  char		*str;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
		 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_LOST], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_LOST], NULL);
  str = my_int_to_str(10 - ((current - start) / 1000));
  vec = vector2f(vec.x + 410, vec.y);
  sfText_setCharacterSize(explo->graph->text, 140);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, new_cat("Time left : ", str));
  sfRenderWindow_drawText(explo->graph->window,
			  explo->graph->text, NULL);
  sfRenderWindow_display(explo->graph->window);
  sfText_setCharacterSize(explo->graph->text, 50);
}

int			death_player(t_explo *explo)
{
  unsigned long long	start;

  start = get_time();
  effect_death(explo);
  while (start + (10 * 1000) > get_time())
    {
      draw_death(explo, start, get_time());
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
	return (1);
      if (sfKeyboard_isKeyPressed(sfKeySpace)
          && !wait_key(explo->graph->window, sfKeySpace))
	return (SUCCESS);
    }
  return (1);
}

int		death(t_explo *explo)
{
  sfVector2i	cpt;

  if (explo->player->hp <= 0)
    {
      if (death_player(explo) == 1)
        return (1);
      else
        {
	  sfView_setCenter(explo->graph->view,
			   vector2f((explo->config->map_size_x / 2) * 256,
				    (explo->config->map_size_y / 2) * 256));
	  explo->player->hp = 100;
          cpt.y = -1;
          while (explo->player->inv[++cpt.y] && (cpt.x = -1))
            while (explo->player->inv[cpt.y][++cpt.x])
              {
                explo->player->inv[cpt.y][cpt.x]->item = -1;
                explo->player->inv[cpt.y][cpt.x]->quantity = -1;
              }
	  draw_all(explo);
        }
    }
  return (SUCCESS);
}

