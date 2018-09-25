/*
** gif_utils.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Sun Oct  8 16:57:05 2017 camille
** Last update Sun Oct  8 17:11:14 2017 camille
*/

#include <stdlib.h>
#include "base.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

char	*my_revstr(char *str)
{
  int	i;
  int	y;
  char	*c;

  c = malloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  while (str[i] != '\0')
    {
      c[i] = str[i];
      i++;
    }
  y = 0;
  while (str[y] != '\0')
    {
      str[y] = c[i - 1];
      i--;
      y++;
    }
  return (str);
}

char		*my_int_to_str(int nb)
{
  int		i;
  char		*str;

  i = 0;
  if ((str = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  if (nb == 0)
    return ("0");
  if (nb < 0)
    {
      str[i] = '-';
      i++;
    }
  while (nb != 0)
    {
      str[i] = nb % 10 + 48;
      nb = nb / 10;
      i++;
    }
  str[i] = '\0';
  str = my_revstr(str);
  return (str);
}

sfSprite	*load_picture(char *str)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((texture = sfTexture_createFromFile(str, NULL)) == NULL)
    {
      if ((sprite = sfSprite_create()) == NULL)
	return (NULL);
      sfSprite_setColor(sprite, sfBlue);
      return (sprite);
    }
  if ((sprite = sfSprite_create()) == NULL)
    return (NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

char		*new_cat(char *start, char *end)
{
  char		*ret;
  int		i;
  int		x;

  i = 0;
  if ((ret = malloc(sizeof(char)
		    * (my_strlen(start) + my_strlen(end) + 1))) == NULL)
    return (NULL);
  while (start[i])
    {
      ret[i] = start[i];
      i++;
    }
  x = 0;
  while (end[x])
    {
      ret[x + i] = end[x];
      x++;
    }
  ret[i + x] = 0;
  return (ret);
}

sfSprite	**create_gif(char *str, int nb)
{
  sfSprite	**gif;
  int		i;

  if ((gif = malloc(sizeof(sfSprite *) * (nb + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb)
    {
      if ((gif[i] = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
					 ".png"))) == NULL)
	return (NULL);
    }
  gif[i] = NULL;
  return (gif);
}
