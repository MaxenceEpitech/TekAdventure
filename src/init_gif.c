/*
** init_gif.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 26 14:34:09 2017 maxence.fourrier
** Last update Wed Oct 11 11:25:09 2017 maxence.fourrier
*/

#include <string.h>
#include "explo.h"

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

sfSprite	***init_gif()
{
  sfSprite	***gif;

  if ((gif = malloc(sizeof(sfSprite **) * NB_GIF)) == NULL
      || (gif[0] = create_gif(GIF_1_NAME, GIF_1_TOTAL)) == NULL
      || (gif[1] = create_gif(GIF_2_NAME, GIF_2_TOTAL)) == NULL
      || (gif[2] = create_gif(GIF_3_NAME, GIF_3_TOTAL)) == NULL
      || (gif[3] = create_gif(GIF_4_NAME, GIF_4_TOTAL)) == NULL
      || (gif[4] = create_gif(GIF_5_NAME, GIF_5_TOTAL)) == NULL
      || (gif[5] = create_gif(GIF_6_NAME, GIF_6_TOTAL)) == NULL
      || (gif[6] = create_gif(GIF_7_NAME, GIF_7_TOTAL)) == NULL
      || (gif[7] = create_gif(GIF_8_NAME, GIF_8_TOTAL)) == NULL
      || (gif[8] = create_gif(GIF_9_NAME, GIF_9_TOTAL)) == NULL
      || (gif[9] = create_gif(GIF_10_NAME, GIF_10_TOTAL)) == NULL
      || (gif[10] = create_gif(GIF_11_NAME, GIF_11_TOTAL)) == NULL
      || (gif[11] = create_gif(GIF_13_NAME, GIF_13_TOTAL)) == NULL
      || (gif[12] = create_gif(GIF_15_NAME, GIF_15_TOTAL)) == NULL
      || (gif[13] = create_gif(GIF_16_NAME, GIF_16_TOTAL)) == NULL
      || (gif[14] = create_gif(GIF_17_NAME, GIF_17_TOTAL)) == NULL
      || (gif[15] = create_gif(GIF_18_NAME, GIF_18_TOTAL)) == NULL)
    return (NULL);
  gif[16] = NULL;
  return (gif);
}
