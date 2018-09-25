/*
** choices_menu.c for tekadventure in /home/camille/semestre2/tekadventure
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Aug 16 16:07:42 2017 camille
** Last update Sun Oct  8 17:14:24 2017 camille
*/

#include <stdlib.h>
#include "base.h"
#include "planet.h"

int	choice_menu(sfVector2i pos)
{
   if ((pos.x >= 264 && pos.x <= 460) && (pos.y >= 446 && pos.y <= 609))
     return (INT_HELP);
  else if ((pos.x >= 1003 && pos.x <= 1282) && (pos.y >= 175 && pos.y <= 367))
    return (INT_NEW);
  else if ((pos.x >= 723 && pos.x <= 957) && (pos.y >= 456 && pos.y <= 638))
    return (INT_LOAD);
  else if ((pos.x >= 85 && pos.x <= 273) && (pos.y >= 232 && pos.y <= 382))
    return (INT_OPT);
  else if ((pos.x >= 1023 && pos.x <= 1147) && (pos.y >= 543 && pos.y <= 638))
    return (INT_QUIT);
  else
    return (0);
}

void	execute_choice_menu(int choice, t_materials *mats)
{
  if (choice == INT_HELP)
    show_help(mats);
  if (choice == INT_OPT)
    show_options(mats);
  if (choice == INT_QUIT)
    free_and_quit(mats);
  else
    load_base(mats);
}

void	show_help(t_materials *mats)
{
  while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, mats->spr[8], NULL);
      sfRenderWindow_display(mats->wdw);
    }
  show_menu(mats);
}

void	show_options(t_materials *mats)
{
  while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, mats->spr[9], NULL);
      sfRenderWindow_display(mats->wdw);
    }
  show_menu(mats);
}

void	coming_soon(t_materials *mats)
{
  while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      sfRenderWindow_clear(mats->wdw, sfBlack);
      sfRenderWindow_drawSprite(mats->wdw, mats->spr[10], NULL);
      sfRenderWindow_display(mats->wdw);
    }
  sfMusic_stop(mats->music[1]);
  free_and_quit(mats);
  exit(0);
}
