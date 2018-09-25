/*
** dashboard.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 11:10:04 2017 camille
** Last update Sun Oct  8 16:56:12 2017 camille
*/

#include "base.h"

sfIntRect	my_rect(int l, int t, int w, int h)
{
  sfIntRect	rect;

  rect.left = l;
  rect.top = t;
  rect.width = w;
  rect.height = h;
  return (rect);
}

void	dashboard_display(t_materials *mats, t_base *base, char type)
{
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_drawSprite(mats->wdw, base->spr[1], NULL);
  if (base->warning == 1)
    sfRenderWindow_drawSprite(mats->wdw, base->spr[17], NULL);
  if (type == 's')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[4], NULL);
  else if (type == 't')
    sfRenderWindow_drawSprite(mats->wdw, base->spr[3], NULL);
  else
    sfRenderWindow_drawSprite(mats->wdw, base->spr[2], NULL);
  sfRenderWindow_display(mats->wdw);
}

void	dashboard_decision(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    coming_soon(mats);
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    start_base(mats, base);
  else
    dashboard_display(mats, base, 'b');
}

void	dashboard_hover(t_materials *mats, t_base *base, sfIntRect yes,
			   sfIntRect no)
{
  if (sfIntRect_contains(&yes, mats->mouse.x, mats->mouse.y) == sfTrue)
    dashboard_display(mats, base, 's');
  else if (sfIntRect_contains(&no, mats->mouse.x, mats->mouse.y) == sfTrue)
    dashboard_display(mats, base, 't');
  else
    dashboard_display(mats, base, 'b');
}

void	use_dashboard(t_materials *mats, t_base *base)
{
  sfIntRect	yes;
  sfIntRect	no;

  yes = my_rect(766, 282, 200, 60);
  no = my_rect(766, 367, 200, 60);
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
	dashboard_decision(mats, base, yes, no);
      else
	dashboard_hover(mats, base, yes, no);
    }
}
