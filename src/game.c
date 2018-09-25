/*
** game.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 09:46:28 2017 maxence.fourrier
** Last update Sun Oct 15 09:40:11 2017 maxence.fourrier
*/

#include "explo.h"

int		game_event(t_explo *explo)
{
  int		ret;

  if (sfKeyboard_isKeyPressed(sfKeyE)
      && (ret = inventory(explo)) != SUCCESS)
    return (ret);
  if (sfMouse_isButtonPressed(sfMouseLeft))
    get_obj_clicked_left(explo);
  if (sfMouse_isButtonPressed(sfMouseRight))
    if (get_obj_clicked_right(explo))
      return (-1);
  if (sfKeyboard_isKeyPressed(sfKeyI))
    craft_inventory(explo);
  return (SUCCESS);
}

int		start_game(t_explo *explo)
{
  int		ret;

  if ((ret = menu(explo)) != SUCCESS)
    return (ret);
  intro(explo);
  explo->game->draw_time = get_time();
  explo->game->time = get_time();
  if ((ret = console(explo, explo->config->console)) != SUCCESS)
    return (ret);
  draw(explo);
  if ((ret = game(explo)) != SUCCESS)
    return (ret);
  return (SUCCESS);
}

int		game(t_explo *explo)
{
  int		ret;

  play_stop_music(explo, vector2i(1, 1), vector2i(0, 0), 0);
  while (1)
    {
      if (death(explo))
	return (SUCCESS);
      music_game(explo);
      explo->game->time = get_time();
      if ((ret = game_event(explo)) != SUCCESS)
	return (ret);
      if (sfKeyboard_isKeyPressed(sfKeyEscape)
	  && !wait_key(explo->graph->window, sfKeyEscape))
	break;
      regen(explo);
      game_time(explo);
      draw(explo);
    }
  return (SUCCESS);
}
