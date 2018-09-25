/*
** gif.c for Project-Master in /home/camille/semestre2/tekadventure/base/src/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Sat Oct  7 15:49:14 2017 camille
** Last update Sun Oct  8 03:29:46 2017 camille
*/

#include <stdlib.h>
#include "base.h"

t_base		*init_sprites_base(t_base *base)
{
  int		i;

  i = 0;
  if ((base->tex = load_tex_base(base->tex)) == NULL)
    return (NULL);
  if ((base->spr = load_spr_base(base->spr, base->tex)) == NULL)
    return (NULL);
  if ((base->ltr = create_gif(LEFT_TO_RIGHT, LTR_TOTAL)) == NULL)
    return (NULL);
  if ((base->rtl = create_gif(RIGHT_TO_LEFT, LTR_TOTAL)) == NULL)
    return (NULL);
  sfSprite_setPosition(base->spr[23], base->player);
  sfSprite_setPosition(base->spr[24], base->player);
  while (i < LTR_TOTAL)
    {
      sfSprite_setPosition(base->ltr[i], base->player);
      sfSprite_setPosition(base->rtl[i], base->player);
      i += 1;
    }
  return (base);
}

void	turn_around(t_materials *mats, t_base *base, char side)
{
  int	i;
  int	j;

  i = 0;
  while (i < LTR_TOTAL)
    {
      j = 0;
      while (j < 6)
	{
	  display_base(mats, base);
	  if (side == 'l')
	    {
	      sfSprite_setPosition(base->rtl[i], base->player);
	      sfRenderWindow_drawSprite(mats->wdw, base->rtl[i], NULL);
	    }
	  else
	    {
	      sfSprite_setPosition(base->ltr[i], base->player);
	      sfRenderWindow_drawSprite(mats->wdw, base->ltr[i], NULL);
	    }
	  j += 1;
	  sfRenderWindow_display(mats->wdw);
	}
      i += 1;
    }
}
