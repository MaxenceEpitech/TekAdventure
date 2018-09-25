/*
** gen_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 14 16:25:36 2017 maxence.fourrier
** Last update Thu Sep 14 19:21:34 2017 maxence.fourrier
*/

#include "explo.h"

int		init_ore_is_unvalide(char **ore, sfVector2i pos)
{
  if (ore[pos.y][pos.x] != ROCK
      || ore[pos.y][pos.x - 1] != ROCK || ore[pos.y][pos.x + 1] != ROCK
      || ore[pos.y - 1][pos.x] != ROCK || ore[pos.y + 1][pos.x] != ROCK
      || ore[pos.y][pos.x - 2] != ROCK || ore[pos.y][pos.x + 2] != ROCK
      || ore[pos.y - 2][pos.x] != ROCK || ore[pos.y + 2][pos.x] != ROCK)
    return (1);
  return (SUCCESS);
}

int		gen_pos_is_unvalide(sfVector2i pos, sfVector2i size,
				    char **ore, int id)
{
  if (pos.x <= 0 || pos.x >= size.x
      || pos.y <= 0 || pos.y >= size.y
      || pos.x + 1 <= 0 || pos.x + 1 >= size.x
      || pos.x - 1 <= 0 || pos.x - 1 >= size.x
      || pos.y + 1 <= 0 || pos.y + 1 >= size.y
      || pos.y - 1 <= 0 || pos.y - 1 >= size.y
      || ore[pos.y][pos.x] != '0' - 1)
    return (1);
  if (ore[pos.y][pos.x - 1] != id && ore[pos.y][pos.x + 1] != id
      && ore[pos.y + 1][pos.x] != id && ore[pos.y - 1][pos.x] != id)
    return (1);
  return (SUCCESS);
}
