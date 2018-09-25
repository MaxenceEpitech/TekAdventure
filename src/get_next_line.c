/*
** get_next_line.c for  in /home/salah/CPE_2016_getnextline
** 
** Made by amine salah
** Login   <salah@epitech.net>
** 
** Started on  Sun Jun 11 11:51:54 2017 amine salah
** Last update Tue Sep  5 11:07:56 2017 maxence.fourrier
*/

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char		*re_alloc(char *str)
{
  char		*restr;
  int		i;

  i = 0;
  if ((restr = malloc((sizeof(char) * my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      restr[i] = str[i];
      i = i + 1;
    }
  restr[i + 1] = '\0';
  free(str);
  return (restr);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  str = malloc(sizeof(char));
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  while ((j = read(fd, buff, 1)) > 0
	 && buff[0] != '\n')
    {
      str = re_alloc(str);
      str[i] = buff[0];
      i = i + 1;
    }
  if (j == 0 && i == 0)
    return (NULL);
  return (str);
}
