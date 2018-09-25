/*
** draw_launcher.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  1 13:56:52 2017 maxence.fourrier
** Last update Sun Oct  1 16:38:17 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_background_launcher(t_explo *explo,
					 sfVector2f vec)
{
  sfSprite_setPosition(explo->sprite[SPR_LAUNCHER_B], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[SPR_LAUNCHER_B], NULL);
}

void		draw_amount_launcher(t_explo *explo, sfVector2f vec,
				     t_inv *inv)
{
  char		*str;

  sfSprite_setPosition(explo->sprite[SPR_INV_G], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_INV_G], NULL);
  vec.x += 7;
  vec.y += 5;
  sfSprite_setPosition(explo->item[SPR_ANTI], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->item[SPR_ANTI], NULL);
  str = my_int_to_str(inv->quantity);
  if (inv->quantity <= 9)
    vec = vector2f(vec.x + 79, vec.y + 64);
  else
    vec = vector2f(vec.x + 60, vec.y + 64);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, str);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
}

void		draw_add_button_launcher(t_explo *explo, sfVector2f vec,
					 sfVector2i click, int i)
{
  int		nb;

  if (inv_contain(explo, ANTI - '0' + 1) > 0)
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      nb = SPR_ADD_G;
      if ((i == 1 && click.x >= 80 && click.x < 230
	   && click.y >= 40 && click.y < 190)
	  || (i == 2 && click.x >= 1030 && click.x < 1180
	      && click.y >= 490 && click.y < 640)
	  || (i == 3 && click.x >= 80 && click.x < 230
	      && click.y >= 510 && click.y < 660))
        nb++;
    }
  else
    nb = SPR_ADD_R;
  sfSprite_setPosition(explo->sprite[nb], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->sprite[nb], NULL);
}

void		draw_launch(t_explo *explo, sfVector2f vec,
			    sfVector2i click)
{
  vec.x += 950;
  vec.y += 120;
  if (click.x >= 900 && click.x < 1250
      && click.y >= 20 && click.y < 380)
    {
      vec.x += 30;
      vec.y += 20;
      sfText_setCharacterSize(explo->graph->text, 70);
    }
  else
    sfText_setCharacterSize(explo->graph->text, 90);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setString(explo->graph->text, "Launch");
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
  sfText_setCharacterSize(explo->graph->text, 50);
}

void		draw_launcher(t_explo *explo, t_placed_mod *placed)
{
  sfVector2f	vec;
  sfVector2i	click;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
                 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  draw_background_launcher(explo, vec);
  draw_launcher_button(explo, placed, click, vec);
  draw_launch(explo, vec, click);
}
