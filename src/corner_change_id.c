/*
** utils_change_id.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 12:28:02 2017 maxence.fourrier
** Last update Sun Oct  8 23:08:56 2017 jean-baptiste
*/

#include "explo.h"

int		is_corner_down_left(int **map, sfVector2i pos,
				    int floor_pos, int floor_next)
{
  if (map[pos.y + 1][pos.x - 1] == floor_next)
    {
      if (map[pos.y][pos.x - 1] == floor_next
	  && map[pos.y + 1][pos.x] == floor_next)
	{
	  map[pos.y][pos.x] = 18;
	  return (1);
	}
      else if (map[pos.y][pos.x - 1] == floor_pos
	       && map[pos.y + 1][pos.x] == floor_pos)
	{
	  map[pos.y][pos.x] = 11;
	  return (1);
	}
    }
  return (SUCCESS);
}

int		is_corner_down_right(int **map, sfVector2i pos,
				     int floor_pos, int floor_next)
{
  if (map[pos.y + 1][pos.x + 1] == floor_next)
    {
      if (map[pos.y][pos.x + 1] == floor_next
	  && map[pos.y + 1][pos.x] == floor_next)
	{
	  map[pos.y][pos.x] = 18;
	  return (1);
	}
      else if (map[pos.y][pos.x + 1] == floor_pos
	       && map[pos.y + 1][pos.x] == floor_pos)
	{
	  map[pos.y][pos.x] = 12;
	  return (1);
	}
    }
  return (SUCCESS);
}

int		is_corner_up_right(int **map, sfVector2i pos,
				   int floor_pos, int floor_next)
{
  if (map[pos.y - 1][pos.x + 1] == floor_next)
    {
      if (map[pos.y][pos.x + 1] == floor_next
	  && map[pos.y - 1][pos.x] == floor_next)
	{
	  map[pos.y][pos.x] = 15;
	  return (1);
	}
      else if (map[pos.y][pos.x + 1] == floor_pos
	       && map[pos.y - 1][pos.x] == floor_pos)
	{
	  map[pos.y][pos.x] = 13;
	  return (1);
	}
    }
  return (SUCCESS);
}

int		is_corner_up_left(int **map, sfVector2i pos,
				  int floor_pos, int floor_next)
{
  if (map[pos.y - 1][pos.x - 1] == floor_next)
    {
      if (map[pos.y][pos.x - 1] == floor_next
	  && map[pos.y - 1][pos.x] == floor_next)
	{
	  map[pos.y][pos.x] = 16;
	  return (1);
	}
      else if (map[pos.y][pos.x - 1] == floor_pos
	       && map[pos.y - 1][pos.x] == floor_pos)
	{
	  map[pos.y][pos.x] = 14;
	  return (1);
	}
    }
  return (SUCCESS);
}
