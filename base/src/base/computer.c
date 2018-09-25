/*
** computer.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 11:05:48 2017 camille
** Last update Wed Oct  4 14:37:35 2017 camille
*/

#include <time.h>
#include <stdlib.h>
#include "base.h"

void	scan_ok(t_materials *mats, t_base *base)
{
  sfTime	t;

  t.microseconds = 1000000;
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[11], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_display(mats->wdw);
  sfSleep(t);
  start_base(mats, base);
}

void	scan_error(t_materials *mats, t_base *base)
{
  int		i;
  sfTime	t;

  i = 0;
  t.microseconds = 200000;
  base->warning = 1;
  while (i < 4)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[12], NULL);
      sfRenderWindow_display(mats->wdw);
      sfSleep(t);
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[13], NULL);
      sfRenderWindow_display(mats->wdw);
      sfSleep(t);
      i += 1;
    }
  start_base(mats, base);
}

void	scan(t_materials *mats, t_base *base)
{
  sfTime	t;

  t.microseconds = 1200000;
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[10], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_display(mats->wdw);
  sfSleep(t);
  srand(time(NULL));
  if (rand() % 4 == 1 || base->warning == 1)
    scan_error(mats, base);
  else
    scan_ok(mats, base);
}
void	computer_display(t_materials *mats, t_base *base, char type)
{
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  if (type == 'y')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[16], NULL);
  else if (type == 'n')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[15], NULL);
  else
    sfRenderWindow_drawSprite(mats->wdw, base->spr[14], NULL);
  sfRenderWindow_display(mats->wdw);
}

void	computer_decision(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    scan(mats, base);
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    start_base(mats, base);
  else
    computer_display(mats, base, 'b');
}

void	computer_hover(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    computer_display(mats, base, 'y');
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    computer_display(mats, base, 'n');
  else
    computer_display(mats, base, 'b');
}

void	use_computer(t_materials *mats, t_base *base)
{
  sfIntRect	yes;
  sfIntRect	no;

  yes = my_rect(513, 324, 115, 56);
  no = my_rect(670, 324, 95, 56);
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[2], NULL);
  sfRenderWindow_display(mats->wdw);
  while (sfRenderWindow_isOpen(mats->wdw))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(mats->wdw);
      mats->mouse = sfMouse_getPositionRenderWindow(mats->wdw);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	computer_decision(mats, base, yes, no);
      else
	computer_hover(mats, base, yes, no);
    }
}
