/*
** depth.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 18:49:25 2017 maxence.fourrier
** Last update Sun Oct  8 22:32:57 2017 maxence.fourrier
*/

#include "explo.h"

int		**fill_depth(t_config *config, int **map)
{
  int		x;
  int		y;

  y = 0;
  while (y < config->map_size_y)
    {
      x = 0;
      while (x < config->map_size_x)
        {
          map[y][x] = 0;
          x++;
        }
      map[y][x] = -1;
      y++;
    }
  map[y] = NULL;
  return (map);
}

int		**init_depth(t_config *config)
{
  int		**depth;
  int		i;

  if ((depth = malloc(sizeof(int**) * (config->map_size_y + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < config->map_size_y)
    if ((depth[i] = malloc(sizeof(int*) * (config->map_size_x + 1))) == NULL)
      return (NULL);
  depth = fill_depth(config, depth);
  return (depth);
}
