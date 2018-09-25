/*
** get_prod.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 10:39:36 2017 maxence.fourrier
** Last update Sun Oct  1 12:20:04 2017 maxence.fourrier
*/

#include "explo.h"

int		get_prod_module(t_explo *explo, t_placed_mod *placed)
{
  int		ret;

  ret = 0;
  if (placed->type == MODULE_SOLAR && placed->on && placed->link
      && explo->day->day >= 0 && explo->day->day < NB_HOUR / 2)
    ret += (1 + placed->upgrade) * 10;
  if (placed->type == MODULE_COAL && placed->furnace.x)
    ret += 100;
  if (placed->type == MODULE_COAL && placed->furnace.y)
    ret += 100;
  if (placed->type == MODULE_NUCLEAR && placed->furnace.x)
    ret += 1000;
  if (placed->type == MODULE_NUCLEAR && placed->furnace.y)
    ret += 1000;
  return (ret);
}

int		get_prod_base(t_explo *explo, t_placed_mod *placed)
{
  int		ret;

  ret = 0;
  while (placed != NULL)
    {
      ret += get_prod_module(explo, placed);
      placed = placed->next;
    }
  return (ret);
}
