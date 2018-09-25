/*
** init_rock.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep  5 15:49:03 2017 maxence.fourrier
** Last update Sat Oct  7 00:38:30 2017 maxence.fourrier
*/

#include <time.h>
#include "explo.h"

t_pos		*link_pos_rock(t_pos *list, sfVector2i map,
			       t_game *game, t_config *config)
{
  t_pos		*new;

  if ((new = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  new->vec.x = rand()
    % ((map.x - (BORDER + ROCK_X)) - (BORDER) + 1) + BORDER;
  new->vec.y = rand()
    % ((map.y - (BORDER + ROCK_Y)) - (BORDER) + 1) + BORDER;
  while (not_placeable(list, new->vec,
                       vector2i(ROCK_X, ROCK_Y), config) == ERROR
	 || not_placeable(game->fire, new->vec,
                          vector2i(FIRE_X, FIRE_Y), config) == ERROR
         || not_placeable(game->mountain, new->vec,
                          vector2i(MOUNTAIN_X, MOUNTAIN_Y), config) == ERROR)
    {
      new->vec.x = rand()
	% ((map.x - (BORDER + ROCK_X)) - (BORDER) + 1) + BORDER;
      new->vec.y = rand()
	% ((map.y - (BORDER + ROCK_Y)) - (BORDER) + 1) + BORDER;
    }
  new->type = my_rand(0, 3);
  new->draw = 0;
  new->alive = 1;
  new->next = list;
  return (new);
}

t_pos		*init_list_rock(int list_size, sfVector2i map,
				t_game *game, t_config *config)
{
  t_pos		*list;
  int		i;

  if ((list = malloc(sizeof(t_pos))) == NULL)
    return (NULL);
  list = NULL;
  i = -1;
  while (++i < list_size)
    if ((list = link_pos_rock(list, map, game, config)) == NULL)
      return (NULL);
  return (list);
}
