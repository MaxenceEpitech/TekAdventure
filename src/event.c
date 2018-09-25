/*
** event.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep  7 16:25:05 2017 maxence.fourrier
** Last update Wed Sep 27 12:51:14 2017 maxence.fourrier
*/

#include "explo.h"

int		wait_key(sfRenderWindow *window, sfKeyCode key)
{
  sfEvent	event;

  sfRenderWindow_waitEvent(window, &event);
  while (event.type != sfEvtKeyReleased
	 || event.key.code != key)
    sfRenderWindow_waitEvent(window, &event);
  return (SUCCESS);
}

int		wait_mouse(sfRenderWindow *window)
{
  sfEvent	event;

  sfRenderWindow_waitEvent(window, &event);
  while (event.type != sfEvtMouseButtonReleased)
    sfRenderWindow_waitEvent(window, &event);
  usleep(100000);
  return (SUCCESS);
}

int		get_event()
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    return (ESCAPE);
  if (sfKeyboard_isKeyPressed(sfKeyLeft)
      || sfKeyboard_isKeyPressed(sfKeyQ))
    return (LEFT);
  if (sfKeyboard_isKeyPressed(sfKeyRight)
      || sfKeyboard_isKeyPressed(sfKeyD))
    return (RIGHT);
  if (sfKeyboard_isKeyPressed(sfKeyDown)
      || sfKeyboard_isKeyPressed(sfKeyS))
    return (DOWN);
  if (sfKeyboard_isKeyPressed(sfKeyUp)
      || sfKeyboard_isKeyPressed(sfKeyZ))
    return (UP);
  if (sfKeyboard_isKeyPressed(sfKeyE))
    return (INVENTORY);
  if (sfKeyboard_isKeyPressed(sfKeyI))
    return (CRAFT);
  return (SUCCESS);
}
