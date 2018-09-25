/*
** draw_button_launcher.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  1 15:23:13 2017 maxence.fourrier
** Last update Sun Oct  8 23:08:21 2017 jean-baptiste
*/

#include "explo.h"

void		draw_launcher_button_first(t_explo *explo, sfVector2f vec,
					   sfVector2i click, t_inv *inv)
{
  vec.x += 80;
  vec.y += 40;
  if (inv->quantity == 0)
    {
      draw_add_button_launcher(explo, vec, click, 1);
      vec.x += 200;
      vec.y += 10;
      draw_amount_launcher(explo, vec, inv);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_DONE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_DONE], NULL);
    }
}

void		draw_launcher_button_second(t_explo *explo, sfVector2f vec,
					    sfVector2i click, t_inv *inv)
{
  vec.x += 860;
  vec.y += 500;
  if (inv->quantity == 0)
    {
      draw_amount_launcher(explo, vec, inv);
      vec.x += 170;
      vec.y -= 10;
      draw_add_button_launcher(explo, vec, click, 2);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_DONE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_DONE], NULL);
    }
}

void		draw_launcher_button_third(t_explo *explo, sfVector2f vec,
					   sfVector2i click, t_inv *inv)
{
  vec.x += 80;
  vec.y += 510;
  if (inv->quantity == 0)
    {
      draw_add_button_launcher(explo, vec, click, 3);
      vec.x += 200;
      vec.y += 10;
      draw_amount_launcher(explo, vec, inv);
    }
  else
    {
      sfSprite_setPosition(explo->sprite[SPR_DONE], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[SPR_DONE], NULL);
    }
}

void		draw_launcher_button(t_explo *explo, t_placed_mod *placed,
				     sfVector2i click, sfVector2f vec)
{
  draw_launcher_button_first(explo, vec, click, placed->inv[0][0]);
  draw_launcher_button_second(explo, vec, click, placed->inv[0][1]);
  draw_launcher_button_third(explo, vec, click, placed->inv[0][2]);
}
