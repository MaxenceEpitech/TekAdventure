/*
** check_can_place.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 16:29:26 2017 maxence.fourrier
** Last update Fri Oct  6 23:44:28 2017 maxence.fourrier
*/

#include "explo.h"

int		can_place_top_right(sfVector2f click, t_limit **limit,
				    t_placed_mod *placed, int item)
{
  if (click.x + limit[item]->bot.x
      >= placed->pos.x + limit[placed->type]->top.x
      && click.x + limit[item]->bot.x
      < placed->pos.x + limit[placed->type]->bot.x
      && click.y + limit[item]->top.y
      >= placed->pos.y + limit[placed->type]->top.y
      && click.y + limit[item]->top.y
      < placed->pos.y + limit[placed->type]->bot.y)
    return (1);
  if (placed->pos.x + limit[placed->type]->bot.x
      >= click.x + limit[item]->top.x
      && placed->pos.x + limit[placed->type]->bot.x
      < click.x + limit[item]->bot.x
      && placed->pos.y + limit[placed->type]->top.y
      >= click.y + limit[item]->top.y
      && placed->pos.y + limit[placed->type]->top.y
      < click.y + limit[item]->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_left(sfVector2f click, t_limit **limit,
				   t_placed_mod *placed, int item)
{
  if (click.x + limit[item]->top.x
      >= placed->pos.x + limit[placed->type]->top.x
      && click.x + limit[item]->top.x
      < placed->pos.x + limit[placed->type]->bot.x
      && click.y + limit[item]->bot.y
      >= placed->pos.y + limit[placed->type]->top.y
      && click.y + limit[item]->bot.y
      < placed->pos.y + limit[placed->type]->bot.y)
    return (1);
  if (placed->pos.x + limit[placed->type]->top.x
      >= click.x + limit[item]->top.x
      && placed->pos.x + limit[placed->type]->top.x
      < click.x + limit[item]->bot.x
      && placed->pos.y + limit[placed->type]->bot.y
      >= click.y + limit[item]->top.y
      && placed->pos.y + limit[placed->type]->bot.y
      < click.y + limit[item]->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_top_left(sfVector2f click, t_limit **limit,
				   t_placed_mod *placed, int item)
{
  if (click.x + limit[item]->bot.x
      >= placed->pos.x + limit[placed->type]->top.x
      && click.x + limit[item]->bot.x
      < placed->pos.x + limit[placed->type]->bot.x
      && click.y + limit[item]->bot.y
      >= placed->pos.y + limit[placed->type]->top.y
      && click.y + limit[item]->bot.y
      < placed->pos.y + limit[placed->type]->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_bot_right(sfVector2f click, t_limit **limit,
				    t_placed_mod *placed, int item)
{
  if (click.x + limit[item]->top.x
      >= placed->pos.x + limit[placed->type]->top.x
      && click.x + limit[item]->top.x
      < placed->pos.x + limit[placed->type]->bot.x
      && click.y + limit[item]->top.y
      >= placed->pos.y + limit[placed->type]->top.y
      && click.y + limit[item]->top.y
      < placed->pos.y + limit[placed->type]->bot.y)
    return (1);
  return (SUCCESS);
}

int		can_place_center(sfVector2f click, t_limit **limit,
				 t_placed_mod *placed, int item)
{
  if (click.x >= placed->pos.x + limit[placed->type]->top.x
      && click.x < placed->pos.x + limit[placed->type]->bot.x
      && click.y >= placed->pos.y + limit[placed->type]->top.y
      && click.y < placed->pos.y + limit[placed->type]->bot.y)
    return (1);
  return (SUCCESS);
}
