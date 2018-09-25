/*
** clear.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep  7 09:53:14 2017 maxence.fourrier
** Last update Sun Oct  8 22:21:34 2017 maxence.fourrier
*/

#include "explo.h"

void		clear_sprite(sfSprite **sprite)
{
  int		y;

  y = -1;
  while (sprite[++y])
    sfSprite_destroy(sprite[y]);
  free(sprite);
}

void		clear_tab(char **map)
{
  int		y;

  y = -1;
  while (map[++y])
    free(map[y]);
  free(map);
}

void		clear_ore(char ***ore)
{
  int		i;
  int		y;

  i = 0;
  while (ore[i])
    {
      y = 0;
      while (ore[i][y])
	{
	  free(ore[i][y]);
	  y++;
	}
      free(ore[i]);
      i++;
    }
  free(ore);
}

void		clear_graph(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->gif[++i])
    clear_sprite(explo->gif[i]);
  free(explo->gif);
  sfRenderWindow_destroy(explo->graph->window);
  sfSprite_destroy(explo->graph->sprite);
  sfTexture_destroy(explo->graph->texture);
  clear_sprite(explo->sprite);
  clear_sprite(explo->item);
}

void		clear_ressources(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->music[++i])
    sfMusic_destroy(explo->music[i]);
  free(explo->config);
  free(explo->game->module);
  free(explo->game->mountain);
  free(explo->game->fire);
  free(explo->game->rock);
  clear_ore(explo->game->ore);
  free(explo->game);
  free(explo->player);
  clear_graph(explo);
  free(explo);
}
