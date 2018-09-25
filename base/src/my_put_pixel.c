/*
** my_put_pixel.c for wolf3d in /home/camille/semestre1/wolf3d
** 
** Made by camille ARBAULT
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Mon May 15 10:46:43 2017 camille ARBAULT
** Last update Wed Aug 16 15:12:42 2017 camille
*/

#include <stdlib.h>
#include "tek.h"

sfUint8		*create_pixel_buffer(int w, int h)
{
  int		i;
  sfUint8*	pixels;

  i = 0;
  pixels = malloc(w * h * 4 * sizeof(*pixels));
  if (pixels == NULL)
    return(NULL);
  while (i < (w * h * 4))
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}

t_my_framebuffer	*create_fbuffer(int w, int h)
{
  t_my_framebuffer	*fb;

  fb = malloc(sizeof(*fb));
  if (fb == NULL)
    return (NULL);
  fb->pixels = create_pixel_buffer(w, h);
  fb->width = w;
  fb->height = h;
  return (fb);
}

void	my_put_pixel(t_my_framebuffer *fb, int x, int y, sfColor color)
{
  if ((x >= 0) && (x < fb->width) && (y >= 0) && (y < fb->height))
    {
      fb->pixels[((fb->width * y) + x) * 4] = color.r;
      fb->pixels[((fb->width * y) + x) * 4 + 1] = color.g;
      fb->pixels[((fb->width * y) + x) * 4 + 2] = color.b;
      fb->pixels[((fb->width * y) + x) * 4 + 3] = color.a;
    }
}
