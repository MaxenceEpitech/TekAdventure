/*
** config_file.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 15 19:43:24 2017 maxence.fourrier
** Last update Thu Oct  5 09:38:42 2017 maxence.fourrier
*/

#include <fcntl.h>
#include "explo.h"

char		*get_line_check(int fd)
{
  char		*ret;
  char          *str;
  int           i;

  if ((str = get_next_line(fd)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && str[i] != '=');
  if (str[i] != '='
      || (ret = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && str[i] != '=')
    ret[i] = str[i];
  ret[i] = 0;
  return (ret);
}

int		check_end_config_file(int fd, char *line)
{
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_7))
    return (error_config_file(LINE_7, E_LINE_7));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_8))
    return (error_config_file(LINE_8, E_LINE_8));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_9))
    return (error_config_file(LINE_9, E_LINE_9));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_10))
    return (error_config_file(LINE_10, E_LINE_10));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_11))
    return (error_config_file(LINE_11, E_LINE_11));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_12))
    return (error_config_file(LINE_12, E_LINE_12));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_13))
    return (error_config_file(LINE_13, E_LINE_13));
  return (SUCCESS);
}

int		config_file_is_valide(char *name)
{
  int		fd;
  char		*line;

  if ((fd = open(name, O_RDONLY)) == -1
      || (line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_1))
    return (error_config_file(LINE_1, E_LINE_1));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_2))
    return (error_config_file(LINE_2, E_LINE_2));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_3))
    return (error_config_file(LINE_3, E_LINE_3));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_4))
    return (error_config_file(LINE_4, E_LINE_4));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_5))
    return (error_config_file(LINE_5, E_LINE_5));
  if ((line = get_line_check(fd)) == NULL
      || !my_strcmp(line, LINE_6))
    return (error_config_file(LINE_6, E_LINE_6));
  if (check_end_config_file(fd, line) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
