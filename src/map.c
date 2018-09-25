/*
** map.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 13:39:33 2017 maxence.fourrier
** Last update Sun Oct  8 13:13:12 2017 maxence.fourrier
*/

#include <time.h>
#include "explo.h"

int		not_placeable(t_pos *pos, sfVector2i vec,
			      sfVector2i size, t_config *config)
{
  if (vec.x < (config->map_size_x / 2 - BASE_X / 2) + RADIUS_BASE
      && vec.x >= (config->map_size_x / 2 - BASE_X / 2) - RADIUS_BASE
      && vec.y < (config->map_size_y / 2 - BASE_Y / 2) + RADIUS_BASE
      && vec.y >= (config->map_size_y / 2 - BASE_Y / 2) - RADIUS_BASE)
    return (ERROR);
  while (pos != NULL)
    {
      if (vec.x < pos->vec.x + size.x && vec.x >= pos->vec.x
	  && vec.y < pos->vec.y + size.y && vec.y >= pos->vec.y)
	return (ERROR);
      pos = pos->next;
    }
  return (SUCCESS);
}

int		**fill_map(t_config *config, int **map)
{
  int		x;
  int		y;

  y = 0;
  while (y < config->map_size_y)
    {
      x = 0;
      while (x < config->map_size_x)
	{
	  map[y][x] = -1;
	  x++;
	}
      map[y][x] = -2;
      y++;
    }
  map[y] = NULL;
  return (map);
}

int		**fill_map_rand(t_config *config, int **map)
{
  int		x;
  int		y;

  y = 0;
  while (y < config->map_size_y)
    {
      x = 0;
      while (x < config->map_size_x)
	{
	  map[y][x] = my_rand(0, 2);
	  x++;
	}
      map[y][x] = -2;
      y++;
    }
  map[y] = NULL;
  return (map);
}

/*
** add gen_biome to init_map
** replace by fill_map_rand(0, 2);
*/

int		**init_map(t_config *config)
{
  int		**map;
  int		i;

  if ((map = malloc(sizeof(int**) * (config->map_size_y + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < config->map_size_y)
    if ((map[i] = malloc(sizeof(int*) * (config->map_size_x + 1))) == NULL)
      return (NULL);
  map = fill_map_rand(config, map);
  return (map);
}
