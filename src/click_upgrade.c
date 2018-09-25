/*
** click_upgrade.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 22:38:17 2017 maxence.fourrier
** Last update Wed Sep 27 22:43:16 2017 maxence.fourrier
*/

#include "explo.h"

int		click_upgrade(t_explo *explo, sfVector2f vec,
			      int *upgrade)
{
  sfVector2i	pos;
  t_placed_mod	*placed;
  int		i;

  placed = get_base_module(explo->game->placed);
  if (sfMouse_isButtonPressed(sfMouseLeft)
      && can_upgrade(explo, explo->game->upgrade[placed->type]
                     [placed->upgrade]))
    {
      pos = sfMouse_getPositionRenderWindow(explo->graph->window);
      if (pos.x >= vec.x && pos.x < vec.x + 150
          && pos.y >= vec.y && pos.y < vec.y + 150)
        {
          i = -1;
          while (upgrade[++i] != -1)
            if (upgrade[i] > 0)
              del_inv(explo->player->inv, i + 1, upgrade[i]);
          placed->upgrade++;
          return (1);
        }
    }
  return (SUCCESS);
}
