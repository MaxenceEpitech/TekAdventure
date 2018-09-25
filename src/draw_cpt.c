/*
** draw_cpt.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 11 15:38:55 2017 maxence.fourrier
** Last update Sun Oct  8 10:59:01 2017 maxence.fourrier
*/

#include "explo.h"

int		init_draw_cpt_y(t_explo *explo)
{
  int		ret;

  ret = (explo->player->pos.y / SPRITE_FLOOR_SIZE)
    - (SCREEN_HEIGHT / SPRITE_FLOOR_SIZE) - 1;
  if (ret < 0)
    return (0);
  if (ret > explo->game->size.y)
    return (explo->game->size.y);
  return (ret + 1);
}

int		init_draw_cpt_x(t_explo *explo)
{
  int		ret;

  ret = (explo->player->pos.x / SPRITE_FLOOR_SIZE)
    - (SCREEN_WIDTH / SPRITE_FLOOR_SIZE) - 1;
  if (ret < 0)
    return (0);
  if (ret > explo->game->size.x)
    return (explo->game->size.x);
  return (ret + 1);
}

sfVector2i	init_draw_max(t_explo *explo)
{
  sfVector2i	max;

  max.x = (explo->player->pos.x / SPRITE_FLOOR_SIZE)
    + (SCREEN_WIDTH / SPRITE_FLOOR_SIZE) + 1;
  max.y = (explo->player->pos.y / SPRITE_FLOOR_SIZE)
    + (SCREEN_HEIGHT / SPRITE_FLOOR_SIZE) + 1;
  if (max.x > explo->game->size.x)
    max.x = explo->game->size.x;
  if (max.x < 0)
    max.x = 0;
  if (max.y > explo->game->size.y)
    max.y = explo->game->size.y;
  if (max.y < 0)
    max.y = 0;
  if (max.x > 0)
    max.x--;
  return (max);
}
