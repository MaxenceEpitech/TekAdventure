/*
** interactions.c for Project-Master in /home/camille/semestre2/tekadventure/base/src/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 10:45:16 2017 camille
** Last update Sun Oct  8 17:05:52 2017 camille
*/

#include <stdlib.h>
#include "base.h"

void	start_base(t_materials *mats, t_base *base)
{
  int	action;

  display_base(mats, base);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[24], NULL);
  sfRenderWindow_display(mats->wdw);
  while (sfRenderWindow_isOpen(mats->wdw))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(mats->wdw);
      action = get_base_action(mats, base);
      if (action == INT_DASH)
	use_dashboard(mats, base);
      else if (action == INT_BED)
	use_bed(mats, base);
      else if (action == INT_DECPOD)
	decontamination_pod(mats, base);
      else if (action == INT_COMP)
	use_computer(mats, base);
      else
	base_movements(mats, base);
    }
}

t_base		*init_coords_base(t_base *base)
{
  if ((base->coords = malloc(sizeof(sfFloatRect) * 6)) == NULL)
    return (NULL);
  base->coords[0].left = 279;
  base->coords[0].top = 260;
  base->coords[0].width = 123;
  base->coords[0].height = 93;
  base->coords[1].left = 211;
  base->coords[1].top = 353;
  base->coords[1].width = 255;
  base->coords[1].height = 103;
  base->coords[2].left = 1055;
  base->coords[2].top = 440;
  base->coords[2].width = 560;
  base->coords[2].height = 180;
  base->coords[3].left = 2617;
  base->coords[3].top = 15;
  base->coords[3].width = 218;
  base->coords[3].height = 430;
  base->coords[4].left = 3150;
  base->coords[4].top = 265;
  base->coords[4].width = 220;
  base->coords[4].height = 500;
  return (base);
}

int	get_base_action(t_materials *mats, t_base *base)
{
  int	i;

  i = 0;
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    {
      mats->mouse = sfMouse_getPositionRenderWindow(mats->wdw);
      while (i < 5)
	{
	  if (sfFloatRect_contains(&base->coords[i], (float)(mats->mouse.x),
				   (float)(mats->mouse.y)) == sfTrue)
	    {
	      if (i == 0 || i == 1)
		return (INT_DASH);
	      else
		return (i);
	    }
	  i += 1;
	}
    }
  return (-1);
}
