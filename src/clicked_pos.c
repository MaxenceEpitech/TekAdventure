/*
** clicked_pos.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 10 17:38:54 2017 maxence.fourrier
** Last update Sun Oct  8 11:35:20 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2i	check_clicked_pos_equ(t_explo *explo)
{
  sfVector2i	vec;
  sfVector2i	ret;

  vec = sfMouse_getPositionRenderWindow(explo->graph->window);
  ret.x = -1;
  ret.y = -1;
  if (!(vec.x >= EQU_X && vec.x < EQU_X + (SIZE_INV_X * INV_DIM_X)
        && vec.y >= EQU_Y && vec.y < EQU_Y + INV_DIM_Y))
    return (ret);
  ret.x = (EQU_X - vec.x) / INV_DIM_X;
  ret.y = (EQU_Y - vec.y) / INV_DIM_Y;
  ret.x *= -1;
  ret.y *= -1;
  ret.y += SIZE_INV_Y;
  return (ret);
}

sfVector2i	check_clicked_pos(t_explo *explo)
{
  sfVector2i	vec;
  sfVector2i	ret;

  vec = sfMouse_getPositionRenderWindow(explo->graph->window);
  ret.x = -1;
  ret.y = -1;
  if (!(vec.x >= INV_X && vec.x < INV_X + (SIZE_INV_X * INV_DIM_X)
        && vec.y >= INV_Y && vec.y < INV_Y + (SIZE_INV_Y * INV_DIM_Y)))
    return (ret);
  ret.x = (INV_X - vec.x) / INV_DIM_X;
  ret.y = (INV_Y - vec.y) / INV_DIM_Y;
  ret.x *= -1;
  ret.y *= -1;
  return (ret);
}
