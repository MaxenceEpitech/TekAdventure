/*
** laser.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src/maxence
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 16:41:47 2017 maxence.fourrier
** Last update Mon Oct  9 19:05:28 2017 maxence.fourrier
*/

#include "explo.h"

void		click_laser(t_explo *explo, t_placed_mod *placed)
{
  if (sfMouse_isButtonPressed(sfMouseLeft)
      && placed->inv[0][0]->item > 0)
    {
      placed->inv[0][0]->item--;
      add_item_inv_console(explo->player->inv, FOOD - '0' + 1, 1);
      wait_mouse(explo->graph->window);
    }
}

int		laser(t_explo *explo, t_placed_mod *placed)
{
  if (placed->inv[0][0]->item == -1)
    placed->inv[0][0]->item = 0;
  while (1)
    {
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
        break;
      explo->game->time = get_time();
      regen(explo);
      draw_laser(explo, placed);
      sfRenderWindow_display(explo->graph->window);
    }
  return (SUCCESS);
}
