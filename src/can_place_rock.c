/*
** can_place_rock.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 22:27:27 2017 maxence.fourrier
** Last update Sat Oct  7 00:37:13 2017 maxence.fourrier
*/

#include "explo.h"

int		can_place_top_right_rock(sfVector2f click, t_limit *limit,
					 t_pos *rock, t_explo *explo)
{
  if (click.x + limit->bot.x
      >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x && click.x + limit->bot.x
      < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x && click.y + limit->top.y
      >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y && click.y + limit->top.y
      < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  if ((rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x
      >= click.x + limit->top.x && (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x
      < click.x + limit->bot.x && (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y
      >= click.y + limit->top.y && (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y
      < click.y + limit->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_left_rock(sfVector2f click, t_limit *limit,
					t_pos *rock, t_explo *explo)
{
  if (click.x + limit->top.x
      >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x && click.x + limit->top.x
      < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x && click.y + limit->bot.y
      >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y && click.y + limit->bot.y
      < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  if ((rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x
      >= click.x + limit->top.x && (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x
      < click.x + limit->bot.x && (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y
      >= click.y + limit->top.y && (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y
      < click.y + limit->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_top_left_rock(sfVector2f click, t_limit *limit,
					t_pos *rock, t_explo *explo)
{
  if (click.x + limit->bot.x
      >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x && click.x + limit->bot.x
      < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x && click.y + limit->bot.y
      >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y && click.y + limit->bot.y
      < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_right_rock(sfVector2f click, t_limit *limit,
					 t_pos *rock, t_explo *explo)
{
  if (click.x + limit->top.x
      >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x && click.x + limit->top.x
      < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x && click.y + limit->top.y
      >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y && click.y + limit->top.y
      < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  if (click.x >= (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].x
      && click.x < (rock->vec.x * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].x
      && click.y >= (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[0][rock->type].y
      && click.y < (rock->vec.y * SPRITE_FLOOR_SIZE)
      + explo->game->rock_limit[1][rock->type].y)
    return (1);
  return (SUCCESS);
}

int		can_place_rock(t_pos *rock, sfVector2f click,
			       int item, t_explo *explo)
{
  while (rock != NULL)
    {
      if (rock->alive)
	if (can_place_top_right_rock(click, explo->game->limit[item],
				     rock, explo)
	    || can_place_bot_left_rock(click, explo->game->limit[item],
				       rock, explo)
	    || can_place_bot_right_rock(click, explo->game->limit[item],
					rock, explo)
	    || can_place_top_left_rock(click, explo->game->limit[item],
				       rock, explo))
	  return (SUCCESS);
      rock = rock->next;
    }
  return (1);
}
