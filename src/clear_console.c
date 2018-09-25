/*
** clear_console.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadventure/jb_detection
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 12:08:09 2017 maxence.fourrier
** Last update Tue Oct  3 09:37:23 2017 maxence.fourrier
*/

#include <stdlib.h>
#include "explo.h"

void		usage_clear()
{
  my_putstr(USAGE_CLEAR);
  my_putstr(USE_CLEAR_INV);
  my_putstr(USE_CLEAR_MAP);
}

int		clear_elements(char **tab, t_explo *explo)
{
  sfVector2i	cpt;

  if (tab[1] == NULL)
    usage_clear();
  else if (my_strcmp(tab[1], "inventory") == 1)
    {
      my_putstr(INV_CLEAR);
      cpt.y = -1;
      while (explo->player->inv[++cpt.y] && (cpt.x = -1))
	while (explo->player->inv[cpt.y][++cpt.x])
	  {
	    explo->player->inv[cpt.y][cpt.x]->item = -1;
	    explo->player->inv[cpt.y][cpt.x]->quantity = -1;
	  }
    }
  else if (my_strcmp(tab[1], "map") == 1)
    {
      my_putstr(MAP_CLEAR);
      while (explo->game->placed->next != NULL)
	explo->game->placed = explo->game->placed->next;
    }
  else
    usage_clear();
  return (SUCCESS);
}
