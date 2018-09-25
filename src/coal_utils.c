/*
** coal_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 29 12:55:12 2017 maxence.fourrier
** Last update Fri Sep 29 20:51:23 2017 maxence.fourrier
*/

#include "explo.h"

void		check_first_furnace(t_explo *explo, t_placed_mod *placed,
				    sfVector2i click)
{
  if (click.x >= 40 && click.x < 190
      && click.y >= 412 && click.y < 562
      && placed->inv[0][0]->quantity < 9)
    {
      placed->inv[0][0]->quantity++;
      del_inv(explo->player->inv, COAL - '0' + 1, 1);
    }
}

void		check_second_furnace(t_explo *explo, t_placed_mod *placed,
				     sfVector2i click)
{
  if (click.x >= 1140 && click.x < 1290
      && click.y >= 412 && click.y < 562
      && placed->inv[0][1]->quantity < 9)
    {
      placed->inv[0][1]->quantity++;
      del_inv(explo->player->inv, COAL - '0' + 1, 1);
    }
}

int		click_add_coal(t_explo *explo, t_placed_mod *placed)
{
  sfVector2i	click;

  if (sfMouse_isButtonPressed(sfMouseLeft)
      && inv_contain(explo, COAL + 1 - '0'))
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      check_first_furnace(explo, placed, click);
      check_second_furnace(explo, placed, click);
      return (1);
    }
  return (SUCCESS);
}
