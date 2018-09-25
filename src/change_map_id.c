/*
** change_map_id.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 10:22:56 2017 maxence.fourrier
** Last update Fri Sep 29 10:35:13 2017 maxence.fourrier
*/

#include "explo.h"

void		change_to_dirt_grass(int **map, sfVector2i pos)
{
  if (is_corner_down_left(map, pos, 1, 2)
      || is_corner_down_right(map, pos, 1, 2)
      || is_corner_up_left(map, pos, 1, 2)
      || is_corner_up_right(map, pos, 1, 2))
    return ;
}

int		**change_id(int **map, sfVector2i size)
{
  sfVector2i	pos;

  pos.y = 2;
  while (++pos.y < size.y - 2 && (pos.x = 2))
    while (++pos.x < size.x - 2)
      {
	if (map[pos.y][pos.x] == 1)
	  change_to_dirt_grass(map, pos);
      }
  return (map);
}
