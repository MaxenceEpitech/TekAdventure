/*
** message.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Sep 16 13:27:23 2017 maxence.fourrier
** Last update Sun Oct  8 23:31:57 2017 maxence.fourrier
*/

#include "explo.h"

int		error_config_file(char *str, int line)
{
  my_putstr(UNVALIDE_FILE);
  my_putnbr(line);
  my_putstr(UNVALIDE_FILE_);
  my_putstr(str);
  my_putstr(UNVALIDE_FILE__);
  my_putstr(UNVALIDE_FILE___);
  return (ERROR);
}

int		msg_error(char *file, char *str)
{
  my_putstr(IN_FILE);
  my_putstr(file);
  my_putstr(BACK_LINE);
  my_putstr(str);
  return (ERROR);
}

int		no_file(char *file, char *str)
{
  my_putstr(file);
  my_putstr(FILE_EXIST);
  return (usage(str));
}

int		usage(char *str)
{
  my_putstr(USAGE_1);
  my_putstr(str);
  my_putstr(USAGE_2);
  return (SUCCESS);
}
