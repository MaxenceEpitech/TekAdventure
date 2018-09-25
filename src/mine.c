/*
** mine.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 19:05:13 2017 maxence.fourrier
** Last update Sun Oct  8 13:29:18 2017 maxence.fourrier
*/

#include "explo.h"

void		add_mined_to_inv(t_explo *explo, sfVector2i cpt)
{
  int		item;

  if (explo->game->depth[cpt.y][cpt.x] == 0)
    item = SAND - '0' + 1;
  else
    item = explo->game->ore[explo->game->depth
                            [cpt.y][cpt.x] - 1][cpt.y][cpt.x] - '0' + 1;
  add_item_inv_console(explo->player->inv, item, 1);
}

int		mine(int item, t_explo *explo, sfVector2i click,
		     sfVector2f click_map)
{
  sfVector2i	tmp;

  tmp = vector2i(click_map.x / SPRITE_FLOOR_SIZE,
		 click_map.y / SPRITE_FLOOR_SIZE);
  if (get_dist_btw(explo->player->pos, click_map) > 300)
    return (SUCCESS);
  if (mine_rock(explo, click_map, tmp))
    return (1);
  else if (explo->game->depth[tmp.y][tmp.x] < 3
	   && check_mine_time(tmp, explo))
    {
      add_mined_to_inv(explo, tmp);
      explo->game->depth[tmp.y][tmp.x]++;
      explo->player->power -= POWER_DRILL;
      draw_power(explo);
      return (1);
    }
  return (SUCCESS);
}
