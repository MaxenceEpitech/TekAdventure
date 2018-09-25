/*
** init_mountain.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep  5 14:49:59 2017 maxence.fourrier
** Last update Thu Sep 14 19:28:03 2017 maxence.fourrier
*/

#include <time.h>
#include "explo.h"

t_pos		*link_pos_mountain(t_pos *list, sfVector2i map,
				   t_config *config)
{
  t_pos		*new;

  if ((new = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  new->vec.x = rand()
    % ((map.x - (BORDER + MOUNTAIN_X)) - (BORDER) + 1) + BORDER;
  new->vec.y = rand()
    % ((map.y - (BORDER + MOUNTAIN_Y)) - (BORDER) + 1) + BORDER;
  while (not_placeable(list, new->vec,
		       vector2i(MOUNTAIN_X, MOUNTAIN_Y), config) == ERROR)
    {
      new->vec.x = rand()
	% ((map.x - (BORDER + MOUNTAIN_X)) - (BORDER) + 1) + BORDER;
      new->vec.y = rand()
	% ((map.y - (BORDER + MOUNTAIN_Y)) - (BORDER) + 1) + BORDER;
    }
  new->next = list;
  return (new);
}

t_pos		*init_list_mountain(int list_size, sfVector2i map,
				    t_config *config)
{
  t_pos		*list;
  int		i;

  if ((list = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  list = NULL;
  i = -1;
  while (++i < list_size)
    if ((list = link_pos_mountain(list, map, config)) == NULL)
      return (NULL);
  return (list);
}
