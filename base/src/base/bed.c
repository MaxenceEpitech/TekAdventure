/*
** bed.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 11:08:39 2017 camille
** Last update Sat Oct  7 23:22:15 2017 camille
*/

#include "base.h"

void		fade_to_black(t_materials *mats, t_base *base)
{
  sfTime	t;
  int		i;
  int		j;

  t.microseconds = 40000;
  i = 0;
  while (i < 10)
    {
      sfRenderWindow_drawSprite(mats->wdw, base->spr[22], NULL);
      sfSleep(t);
      sfRenderWindow_display(mats->wdw);
      i += 1;
    }
  while (i > 0)
    {
      j = 0;
      while (j < i)
	{
	  sfRenderWindow_clear(mats->wdw, sfBlack);
	  sfRenderWindow_drawSprite(mats->wdw, base->spr[22], NULL);
	  j += 1;
	}
    }
}

void	use_bed(t_materials *mats, t_base *base)
{
  sfTime	t;

  t.microseconds = 1000000;
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[9], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_display(mats->wdw);
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfSleep(t);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[8], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_display(mats->wdw);
  sfSleep(t);
  start_base(mats, base);
}
