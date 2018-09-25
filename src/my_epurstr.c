/*
** my_epurstr.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Oct  2 12:27:00 2017 maxence.fourrier
** Last update Mon Oct  2 12:27:12 2017 maxence.fourrier
*/

#include "explo.h"

char	*little_verif(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    i += 1;
  if (str[i - 1] == ';')
    str[i - 1] = '\0';
  return (str);
}

char	*my_epurstr(char *str)
{
  int	i;
  int	x;
  char	*str2;

  i = 0;
  x = 0;
  if ((str == NULL)
      || ((str2 = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL))
    return (NULL);
  while (str[i] != '\0')
    {
      while (((str[i] == ' ' || str[i] == '\t') &&
	      (str[i + 1] == ' ' || str[i + 1] == '\t')))
	i++;
      if (str[i] == '\t')
	str[i] = ' ';
      str2[x++] = str[i++];
    }
  str2[x] = '\0';
  if (str2[x - 1] == ' ' || str2[x - 1] == '\t')
    str2[x - 1] = '\0';
  if ((*str2 == ' ' || *str2 == '\t'))
    str2++;
  free(str);
  return (str2);
}
