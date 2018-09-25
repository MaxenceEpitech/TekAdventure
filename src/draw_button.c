/*
** draw_button.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 26 13:04:01 2017 maxence.fourrier
** Last update Sun Oct  8 23:04:58 2017 jean-baptiste
*/

#include "explo.h"

void		button_link(t_explo *explo, sfVector2f vec,
			    sfVector2i click, sfVector2i link)
{
  if (click.x >= 60 && click.x < 210 && click.y >= 320 && click.y < 470)
    {
      sfSprite_setPosition(explo->sprite[link.x], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[link.x], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[link.y], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[link.y], NULL);
    }
}

void		button_upgrade(t_explo *explo, sfVector2f vec,
			       sfVector2i click, sfVector2i upgrade)
{
  if (click.x >= 60 && click.x < 210 && click.y >= 150 && click.y < 300)
    {
      sfSprite_setPosition(explo->sprite[upgrade.x], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[upgrade.x], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[upgrade.y], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[upgrade.y], NULL);
    }
}

void		button_power(t_explo *explo, sfVector2f vec,
			     sfVector2i click, t_placed_mod *placed)
{
  int		nb;

  if (click.x >= 560 && click.x < 710 && click.y >= 490 && click.y < 640)
    {
      if (placed->on == 1)
	nb = SPR_ON_;
      else
	nb = SPR_OFF_;
    }
  else
    {
      if (placed->on == 1)
	nb = SPR_ON;
      else
	nb = SPR_OFF;
    }
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[nb], NULL);
}

void		draw_button(t_explo *explo, sfVector2i upgrade,
			    sfVector2i link,
			    t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfSprite_setPosition(explo->sprite[SPR_INV_SOLAR], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_INV_SOLAR], NULL);
  vec.x += 60;
  vec.y += 150;
  button_upgrade(explo, vec, click, upgrade);
  vec.y += 170;
  button_link(explo, vec, click, link);
  vec.y += 170;
  vec.x += 500;
  button_power(explo, vec, click, placed);
}
