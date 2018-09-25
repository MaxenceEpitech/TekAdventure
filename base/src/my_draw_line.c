/*
** my_draw_line.c for wolf3d in /home/camille/semestre1/wolf3d
** 
** Made by camille ARBAULT
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Mon May 15 10:46:29 2017 camille ARBAULT
** Last update Wed Aug 16 15:11:45 2017 camille
*/

#include <stdlib.h>
#include <math.h>
#include "tek.h"

void	my_draw_line(t_my_framebuffer *fb, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  sfVector2f	dir;
  sfVector2f	pixel;
  double	i;
  double	length;

  dir.x = to.x - from.x;
  dir.y = to.y - from.y;
  length = sqrt (pow(dir.y, 2) + pow (dir.x, 2));
  dir.x = dir.x / length;
  dir.y = dir.y / length;
  i = 0;
  while (i <= length)
    {
      pixel.x = from.x + i * dir.x;
      pixel.y = from.y + i * dir.y;
      if ((pixel.x < fb->width) && (pixel.y < fb->height) &&
	  (pixel.x >= 0) && (pixel.y >= 0))
	my_put_pixel(fb, pixel.x, pixel.y, color);
      i = i + 1;
    }
}
