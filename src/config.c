/*
** config.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 10:53:10 2017 maxence.fourrier
** Last update Sun Oct  8 11:25:33 2017 maxence.fourrier
*/

#include <stdlib.h>
#include <fcntl.h>
#include "explo.h"

char		*add_to_buff(char *buff, char c)
{
  int		i;
  char		*ret;

  if ((ret = malloc(sizeof(char) * (my_strlen(buff) + 2))) == NULL)
    return (NULL);
  i = 0;
  while (buff[i])
    {
      ret[i] = buff[i];
      i++;
    }
  ret[i] = c;
  ret[i + 1] = 0;
  free(buff);
  return (ret);
}

char		*get_next_line(const int fd)
{
  char		*buff;
  char		c;
  int		readed;
  int		cpt;

  cpt = 0;
  if ((buff = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  buff[0] = 0;
  while ((readed = read(fd, &c, 1)) > 0)
    {
      if (readed == 0 && buff[0] == 0)
        return (NULL);
      if (c == '\n' || readed == 0)
        return (buff);
      buff = add_to_buff(buff, c);
      cpt++;
    }
  if ((readed == 0 && buff[0] == 0)
      || cpt == 0)
    return (NULL);
  return (buff);
}

int		get_line_config(int fd)
{
  int		ret;
  char		*str;
  int		i;

  if ((str = get_next_line(fd)) == NULL)
    return (-1);
  i = 0;
  while (str[i] != '=')
    i++;
  ret = atoi(str + i + 1);
  free(str);
  return (ret);
}

t_config	*init_config(char *file)
{
  t_config	*config;
  int		fd;

  if ((config = malloc(sizeof(t_config))) == NULL
      || (fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  config->difficulty = get_line_config(fd);
  config->map_size_x = get_line_config(fd);
  config->map_size_y = get_line_config(fd);
  config->map_mountain = get_line_config(fd);
  config->map_fire = get_line_config(fd);
  config->map_rock = get_line_config(fd);
  config->player_oxy = get_line_config(fd);
  config->player_hp = get_line_config(fd);
  config->player_power = get_line_config(fd);
  config->player_speed = get_line_config(fd);
  config->planets = get_line_config(fd);
  config->console = get_line_config(fd);
  config->storm = get_line_config(fd);
  return (config);
}
