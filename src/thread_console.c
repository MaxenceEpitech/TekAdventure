/*
** thread_console.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadventure/jb_detection
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 12:04:30 2017 maxence.fourrier
** Last update Sun Oct  8 11:26:40 2017 maxence.fourrier
*/

#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include "explo.h"

void		*thread_console(void *arg)
{
  t_explo	*explo;
  char		*command;
  char		**tab;

  explo = arg;
  my_putstr(CONSOLE);
  while ((command = get_next_line(0)))
    {
      if (my_strlen(command) != 0)
	{
	  command = my_epurstr(command);
	  tab = my_str_to_wordtab(command, ' ');
	  detect_utils(tab, explo);
	}
      my_putstr(CONSOLE);
    }
}

int		console(t_explo *explo, int power)
{
  pthread_t	console;

  if (power == 0)
    {
      my_putstr(CONSOLE_OFF);
      return (SUCCESS);
    }
  my_putstr(CONSOLE_ON);
  if (pthread_create(&console, NULL, thread_console, (t_explo*)explo))
    return (ERROR);
  return (SUCCESS);
}
