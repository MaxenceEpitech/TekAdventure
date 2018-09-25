/*
** click_coal_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 29 17:18:00 2017 maxence.fourrier
** Last update Sun Oct  8 23:09:53 2017 jean-baptiste
*/

#include "explo.h"

int		change_furnace_on_other(sfVector2i pos,
					t_placed_mod *placed)
{
  if (placed->furnace.y == 0 && pos.x >= 855 && pos.x < 1020
      && pos.y >= 542 && pos.y < 692
      && (placed->inv[0][0]->quantity > 0 || placed->inv[0][0]->item > 0))
    {
      placed->furnace.y = 1;
      return (1);
    }
  if (placed->furnace.y == 1 && pos.x >= 855 && pos.x < 1020
      && pos.y >= 542 && pos.y < 692)
    {
      placed->furnace.y = 0;
      return (1);
    }
  return (SUCCESS);
}

int		change_furnace_on(sfVector2i pos,
				  t_placed_mod *placed)
{
  if (placed->furnace.x == 0 && pos.x >= 340 && pos.x < 505
      && pos.y >= 542 && pos.y < 692
      && (placed->inv[0][0]->quantity > 0 || placed->inv[0][0]->item > 0))
    {
      placed->furnace.x = 1;
      return (1);
    }
  if (placed->furnace.x == 1 && pos.x >= 340 && pos.x < 505
      && pos.y >= 542 && pos.y < 692)
    {
      placed->furnace.x = 0;
      return (1);
    }
  if (change_furnace_on_other(pos, placed))
    return (1);
  return (SUCCESS);
}

int		change_nuclear_on_other(sfVector2i pos,
					t_placed_mod *placed)
{
  if (placed->furnace.y == 0 && pos.x >= 710 && pos.x < 860
      && pos.y >= 182 && pos.y < 332
      && (placed->inv[0][1]->quantity > 0 || placed->inv[0][1]->item > 0))
    {
      placed->furnace.y = 1;
      return (1);
    }
  if (placed->furnace.y == 1 && pos.x >= 710 && pos.x < 860
      && pos.y >= 182 && pos.y < 332)
    {
      placed->furnace.y = 0;
      return (1);
    }
  return (SUCCESS);
}

int		change_nuclear_on(sfVector2i pos,
				  t_placed_mod *placed)
{
  if (placed->furnace.x == 0 && pos.x >= 480 && pos.x < 630
      && pos.y >= 182 && pos.y < 332
      && (placed->inv[0][0]->quantity > 0 || placed->inv[0][0]->item > 0))
    {
      placed->furnace.x = 1;
      return (1);
    }
  if (placed->furnace.x == 1 && pos.x >= 480 && pos.x < 630
      && pos.y >= 182 && pos.y < 332)
    {
      placed->furnace.x = 0;
      return (1);
    }
  if (change_nuclear_on_other(pos, placed))
    return (1);
  return (SUCCESS);
}
