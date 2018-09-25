/*
** help.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 15:35:22 2017 maxence.fourrier
** Last update Mon Oct  2 16:27:40 2017 maxence.fourrier
*/

#include "explo.h"

int		exit_console(char **tab, t_explo *explo)
{
  my_putstr("exit succesfuly\n");
  exit(0);
}

int		is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (ERROR);
      i++;
    }
  if (i > 5)
    return (ERROR);
  return (SUCCESS);
}

int		print_help_console(char **tab, t_explo *explo)
{
  my_putstr("HELP:\n\n");
  my_putstr("-help   display_help\n");
  my_putstr("-give   give an element or a module\n");
  my_putstr("        synthax : give [element] [nb]\n");
  my_putstr("-clear  clear your inventory or your map\n");
  my_putstr("        synthax : clear inventory / clear map\n");
  my_putstr("-time   change the time\n");
  my_putstr("        synthax : time [hour:minute]\n");
  return (SUCCESS);
}
