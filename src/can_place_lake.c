/*
** can_place_lake.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct  7 09:47:42 2017 maxence.fourrier
** Last update Sat Oct  7 11:55:06 2017 maxence.fourrier
*/

#include "explo.h"

int		can_place_top_right_lake(sfVector2f click, t_limit *limit,
					 t_pos *lake, t_explo *explo)
{
  if (click.x + limit->bot.x
      >= (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21 && click.x + limit->bot.x
      < (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 746 && click.y + limit->top.y
      >= (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 45 && click.y + limit->top.y
      < (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504)
    return (1);
  if ((lake->vec.x * SPRITE_FLOOR_SIZE) + 746
      >= click.x + limit->top.x
      && (lake->vec.x * SPRITE_FLOOR_SIZE) + 746
      < click.x + limit->bot.x
      && (lake->vec.y * SPRITE_FLOOR_SIZE) + 45
      >= click.y + limit->top.y
      && (lake->vec.y * SPRITE_FLOOR_SIZE) + 45
      < click.y + limit->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_left_lake(sfVector2f click, t_limit *limit,
					t_pos *lake, t_explo *explo)
{
  if (click.x + limit->top.x
      >= (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21 && click.x + limit->top.x
      < (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 746 && click.y + limit->bot.y
      >= (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 45 && click.y + limit->bot.y
      < (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504)
    return (1);
  if ((lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21
      >= click.x + limit->top.x && (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21
      < click.x + limit->bot.x && (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504
      >= click.y + limit->top.y && (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504
      < click.y + limit->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_top_left_lake(sfVector2f click, t_limit *limit,
					t_pos *lake, t_explo *explo)
{
  if (click.x + limit->bot.x
      >= (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21 && click.x + limit->bot.x
      < (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 746 && click.y + limit->bot.y
      >= (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 45 && click.y + limit->bot.y
      < (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_right_lake(sfVector2f click, t_limit *limit,
					 t_pos *lake, t_explo *explo)
{
  if (click.x + limit->top.x
      >= (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21 && click.x + limit->top.x
      < (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 746 && click.y + limit->top.y
      >= (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 45 && click.y + limit->top.y
      < (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504)
    return (1);
  if (click.x >= (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 21
      && click.x < (lake->vec.x * SPRITE_FLOOR_SIZE)
      + 746
      && click.y >= (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 45
      && click.y < (lake->vec.y * SPRITE_FLOOR_SIZE)
      + 504)
    return (1);
  return (SUCCESS);
}

int		can_place_lake(t_pos *lake, sfVector2f click,
			       int item, t_explo *explo)
{
  while (lake != NULL)
    {
      if (can_place_top_right_lake(click, explo->game->limit[item],
				   lake, explo)
	  || can_place_bot_left_lake(click, explo->game->limit[item],
				     lake, explo)
	  || can_place_bot_right_lake(click, explo->game->limit[item],
				      lake, explo)
	  || can_place_top_left_lake(click, explo->game->limit[item],
				     lake, explo))
	return (SUCCESS);
      lake = lake->next;
    }
  return (1);
}
