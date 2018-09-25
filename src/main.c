/*
** main.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 09:46:40 2017 maxence.fourrier
** Last update Sun Oct  8 21:26:29 2017 maxence.fourrier
*/

#include <fcntl.h>
#include "explo.h"

int		main(int ac, char **av)
{
  t_explo	*explo;

  if (ac < 2)
    return (usage(av[0]));
  if (open(av[1], O_RDONLY) == -1)
    return (no_file(av[1], av[0]));
  if (config_file_is_valide(av[1]) == ERROR)
    return (ERROR);
  if ((explo = init_explo(av[1])) == NULL
      || start_game(explo) == ERROR)
    return (ERROR);
  clear_ressources(explo);
  return (SUCCESS);
}
