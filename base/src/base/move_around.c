/*
** move_around.c for Project-Master in /home/camille/semestre2/tekadventure/base/src/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
**
** Started on  Wed Oct  4 10:19:23 2017 camille
** Last update Sun Oct  8 04:09:16 2017 camille
*/

#include "base.h"

void	move_coords(t_base *base, int coeff)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      base->coords[i].left += (0.5 * coeff);
      i += 1;
    }
}

void	base_movements(t_materials *mats, t_base *base)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    move_base_left(mats, base);
  else if (sfKeyboard_isKeyPressed(sfKeyRight))
    move_base_right(mats, base);
}

void	move_base_left(t_materials *mats, t_base *base)
{
  if (base->side == 'r')
    turn_around(mats, base, 'l');
  base->side = 'l';
  if (base->bg.x <= 0)
    {
      if (base->player.x > 502)
	base->player.x -= 0.5;
      else
	{
	  base->bg.x += 0.5;
	  move_coords(base, 1);
	}
    }
  else if (base->player.x > -100)
    base->player.x -= 0.5;
  display_base(mats, base);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[23], NULL);
  sfRenderWindow_display(mats->wdw);
}

void	move_base_right(t_materials *mats, t_base *base)
{
  if (base->side == 'l')
    turn_around(mats, base, 'r');
  base->side = 'r';
  if (base->bg.x >= -2659)
    {
      if (base->player.x < 502)
	base->player.x += 0.5;
      else
	{
	  base->bg.x -= 0.5;
	  move_coords(base, -1);
	}
    }
  else if (base->player.x < 1100)
    base->player.x += 0.5;
  display_base(mats, base);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[24], NULL);
  sfRenderWindow_display(mats->wdw);
}

void	display_base(t_materials *mats, t_base *base)
{
  sfSprite_setPosition(base->spr[0], base->bg);
  sfSprite_setPosition(base->spr[1], base->bg);
  sfSprite_setPosition(base->spr[23], base->player);
  sfSprite_setPosition(base->spr[24], base->player);
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[0], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
}
