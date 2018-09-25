/*
** fire.c for tekedv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep  5 15:06:49 2017 maxence.fourrier
** Last update Thu Sep  7 10:13:31 2017 maxence.fourrier
*/

#include <time.h>
#include "explo.h"

t_pos		*link_pos_fire(t_pos *list, sfVector2i map,
			       t_game *game, t_config *config)
{
  t_pos		*new;

  if ((new = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  new->vec.x = rand()
    % ((map.x - (BORDER + FIRE_X)) - (BORDER) + 1) + BORDER;
  new->vec.y = rand()
    % ((map.y - (BORDER + FIRE_Y)) - (BORDER) + 1) + BORDER;
  while (not_placeable(list, new->vec,
		       vector2i(FIRE_X, FIRE_Y), config) == ERROR
	 || not_placeable(game->mountain, new->vec,
			  vector2i(MOUNTAIN_X, MOUNTAIN_Y), config) == ERROR)
    {
      new->vec.x = rand()
	% ((map.x - (BORDER + FIRE_X)) - (BORDER) + 1) + BORDER;
      new->vec.y = rand()
	% ((map.y - (BORDER + FIRE_Y)) - (BORDER) + 1) + BORDER;
    }
  new->next = list;
  return (new);
}

t_pos		*init_list_fire(int list_size, sfVector2i map,
				t_game *game, t_config *config)
{
  t_pos		*list;
  int		i;

  if ((list = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  list = NULL;
  i = -1;
  while (++i < list_size)
    if ((list = link_pos_fire(list, map, game, config)) == NULL)
      return (NULL);
  return (list);
}
