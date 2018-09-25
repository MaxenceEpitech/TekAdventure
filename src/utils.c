/*
** utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep  5 09:58:47 2017 maxence.fourrier
** Last update Wed Sep 27 13:41:42 2017 maxence.fourrier
*/

#include "explo.h"

sfCircleShape	*create_circle(sfVector2f pos, sfColor color,
			       int radius)
{
  sfCircleShape	*circle;

  circle = sfCircleShape_create();
  sfCircleShape_setPosition(circle, pos);
  sfCircleShape_setFillColor(circle, sfTransparent);
  sfCircleShape_setOutlineThickness(circle, 10);
  sfCircleShape_setOutlineColor(circle, color);
  sfCircleShape_setRadius(circle, radius);
  return (circle);
}

char		**fill_map_c(t_config *config, char **map)
{
  int		x;
  int		y;

  y = 0;
  while (y < config->map_size_y)
    {
      x = 0;
      while (x < config->map_size_x)
        {
          map[y][x] = '0' - 1;
          x++;
        }
      map[y][x] = 0;
      y++;
    }
  map[y] = NULL;
  return (map);
}

sfVector2f	vector2f(double x, double y)
{
  sfVector2f	ret;

  ret.x = x;
  ret.y = y;
  return (ret);
}

sfVector3f	vector3f(double x, double y, double z)
{
  sfVector3f	ret;

  ret.x = x;
  ret.y = y;
  ret.z = z;
  return (ret);
}

sfVector2i	vector2i(int x, int y)
{
  sfVector2i	ret;

  ret.x = x;
  ret.y = y;
  return (ret);
}
