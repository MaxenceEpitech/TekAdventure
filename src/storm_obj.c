/*
** storm_obj.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct  3 19:11:36 2017 maxence.fourrier
** Last update Wed Oct  4 10:35:03 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2f	gen_obj_pos(sfVector2f pos)
{
  int		where;

  where = my_rand(0, 3);
  if (where == 0)
    return (vector2f(pos.x - (4 * SPRITE_FLOOR_SIZE),
		     my_rand(pos.y - (2 * SPRITE_FLOOR_SIZE),
			     pos.y + (2 * SPRITE_FLOOR_SIZE))));
  else if (where == 1)
    return (vector2f(my_rand(pos.x - (SCREEN_WIDTH / 2),
			     pos.x + (SCREEN_WIDTH / 2)),
		     pos.y - (3 * SPRITE_FLOOR_SIZE)));
  else if (where == 2)
    return (vector2f(pos.x + (4 * SPRITE_FLOOR_SIZE),
		     my_rand(pos.y - (2 * SPRITE_FLOOR_SIZE),
			     pos.y + (2 * SPRITE_FLOOR_SIZE))));
  else if (where == 3)
    return (vector2f(my_rand(pos.x - (SCREEN_WIDTH / 2),
			     pos.x + (SCREEN_WIDTH / 2)),
		     pos.y + (3 * SPRITE_FLOOR_SIZE)));
}

sfVector2f	gen_obj_dir(sfVector2f player, sfVector2f obj)
{
  sfVector2f	dir;
  int		dist;

  player.x += my_rand(-2 * SPRITE_FLOOR_SIZE, 2 * SPRITE_FLOOR_SIZE);
  player.y += my_rand(-SPRITE_FLOOR_SIZE, SPRITE_FLOOR_SIZE);
  dist = get_dist_btw(player, obj);
  dir.x = (player.x - obj.x) / dist;
  dir.y = (player.y - obj.y) / dist;
  return (dir);
}

void		create_storm_obj(t_explo *explo, t_storm *storm,
				 int amount)
{
  int		i;

  while (amount > 0)
    {
      i = -1;
      while (storm->obj[++i] && storm->obj[i]->alive == 1);
      if (storm->obj[i] == NULL)
	return ;
      storm->obj[i]->alive = 1;
      storm->obj[i]->pos = gen_obj_pos(explo->player->pos);
      storm->obj[i]->dir = gen_obj_dir(explo->player->pos,
				       storm->obj[i]->pos);
      amount--;
    }
}
