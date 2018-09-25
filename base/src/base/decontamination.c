/*
** decontamination.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 11:07:35 2017 camille
** Last update Fri Oct  6 15:16:45 2017 camille
*/

#include "base.h"

void	dec_in_progress(t_materials *mats, t_base *base)
{
  int		i;
  sfTime	t;

  i = 0;
  t.microseconds = 90000;
  base->warning = 1;
  while (i < 5)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[20], NULL);
      sfRenderWindow_display(mats->wdw);
      sfSleep(t);
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[21], NULL);
      sfRenderWindow_display(mats->wdw);
      sfSleep(t);
      i += 1;
    }
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[6], NULL);
  sfRenderWindow_display(mats->wdw);
  t.microseconds = 80000;
  sfSleep(t);
  base->warning = 0;
  start_base(mats, base);
}

void		check_dec(t_materials *mats, t_base *base)
{
  sfTime	t;

  t.microseconds = 100000;
  if (base->warning == 0)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
      sfRenderWindow_drawSprite(mats->wdw, base->spr[7], NULL);
      sfRenderWindow_display(mats->wdw);
      sfSleep(t);
      start_base(mats, base);
    }
  else
    dec_in_progress(mats, base);
}

void	pod_display(t_materials *mats, t_base *base, char type)
{
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  if (type == 'y')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[18], NULL);
  else if (type == 'n')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[19], NULL);
  else
    sfRenderWindow_drawSprite(mats->wdw, base->spr[5], NULL);
  sfRenderWindow_display(mats->wdw);
}

void	pod_decision(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    check_dec(mats, base);
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    start_base(mats, base);
  else
    pod_display(mats, base, 'b');
}

void	pod_hover(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    pod_display(mats, base, 'y');
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    pod_display(mats, base, 'n');
  else
    pod_display(mats, base, 'b');
}

void	decontamination_pod(t_materials *mats, t_base *base)
{
  sfIntRect	yes;
  sfIntRect	no;

  yes = my_rect(542, 360, 114, 36);
  no = my_rect(690, 360, 80, 36);
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[5], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  sfRenderWindow_display(mats->wdw);
  while (sfRenderWindow_isOpen(mats->wdw))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(mats->wdw);
      mats->mouse = sfMouse_getPositionRenderWindow(mats->wdw);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	pod_decision(mats, base, yes, no);
      else
	pod_hover(mats, base, yes, no);
    }
}
