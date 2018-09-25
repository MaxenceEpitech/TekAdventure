/*
** menu.c for tekadventure in /home/camille/semestre2/tekadventure
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Aug 16 12:01:12 2017 camille
** Last update Mon Aug 21 14:57:55 2017 salah
*/

#include <stdlib.h>
#include "tek.h"

void	show_menu(t_materials *mats)
{
  sfVector2i	mouse_pos;
  int		choice;
  int		shown;

  choice = 0;
  shown = 2;
  sfMusic_setLoop(mats->music[1], sfTrue);
  sfMusic_play(mats->music[1]);
  sfRenderWindow_clear(mats->wdw, sfBlack);
  sfRenderWindow_setMouseCursorVisible(mats->wdw, sfTrue);
  sfRenderWindow_drawSprite(mats->wdw, mats->spr[2], NULL);
  sfRenderWindow_display(mats->wdw);
  while (choice == 0)
    {
      mouse_pos = sfMouse_getPositionRenderWindow(mats->wdw);
      shown = menu_what_to_display(mouse_pos, shown, mats);
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	choice = choice_menu(mouse_pos);
    }
  execute_choice_menu(choice, mats);
}

int	menu_what_to_display(sfVector2i pos, int shown, t_materials *mats)
{
  if ((pos.x >= 264 && pos.x <= 460) && (pos.y >= 446 && pos.y <= 609))
    return (draw_sprite_menu(3, shown, mats));
  else if ((pos.x >= 1003 && pos.x <= 1282) && (pos.y >= 175 && pos.y <= 367))
    return (draw_sprite_menu(4, shown, mats));
  else if ((pos.x >= 723 && pos.x <= 957) && (pos.y >= 456 && pos.y <= 638))
    return (draw_sprite_menu(5, shown, mats));
  else if ((pos.x >= 85 && pos.x <= 273) && (pos.y >= 232 && pos.y <= 382))
    return (draw_sprite_menu(6, shown, mats));
  else if ((pos.x >= 1023 && pos.x <= 1147) && (pos.y >= 543 && pos.y <= 638))
    return (draw_sprite_menu(7, shown, mats));
  else
    return (draw_sprite_menu(2, shown, mats));
}

int	draw_sprite_menu(int sprite, int shown, t_materials *mats)
{
  if (sprite != shown)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, mats->spr[sprite], NULL);
      sfRenderWindow_display(mats->wdw);
    }
  return (sprite);
}
