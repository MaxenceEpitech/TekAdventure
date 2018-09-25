/*
** init_limit.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 24 17:21:05 2017 maxence.fourrier
** Last update Fri Oct 13 13:39:09 2017 maxence.fourrier
*/

#include "explo.h"

t_limit		**init_move_pos_other(t_limit **hit_box)
{
  hit_box[MODULE_FUSION]->top = vector2f(20, 20);
  hit_box[MODULE_FUSION]->bot = vector2f(550, 300);
  hit_box[MODULE_CHEST]->top = vector2f(4, 20);
  hit_box[MODULE_CHEST]->bot = vector2f(130, 75);
  hit_box[MODULE_LASER]->top = vector2f(-100, -50);
  hit_box[MODULE_LASER]->bot = vector2f(100, 50);
  hit_box[11] = NULL;
  return (hit_box);
}

t_limit		**init_move_pos()
{
  t_limit	**hit_box;
  int		i;

  if ((hit_box = malloc(sizeof(t_limit*) * (NB_LIMIT + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < NB_LIMIT)
    if ((hit_box[i++] = malloc(sizeof(t_limit))) == NULL)
      return (NULL);
  hit_box[MODULE_BASE]->top = vector2f(45, 75);
  hit_box[MODULE_BASE]->bot = vector2f(250, 180);
  hit_box[MODULE_SOLAR]->top = vector2f(15, 145);
  hit_box[MODULE_SOLAR]->bot = vector2f(230, 220);
  hit_box[MODULE_COAL]->top = vector2f(10, 200);
  hit_box[MODULE_COAL]->bot = vector2f(400, 440);
  hit_box[MODULE_LAUNCHER]->top = vector2f(30, 30);
  hit_box[MODULE_LAUNCHER]->bot = vector2f(580, 440);
  hit_box[MODULE_NUCLEAR]->top = vector2f(10, 120);
  hit_box[MODULE_NUCLEAR]->bot = vector2f(400, 300);
  hit_box = init_move_pos_other(hit_box);
  return (hit_box);
}

t_limit		**init_limit_click(t_limit **limit)
{
  limit[MODULE_NUCLEAR]->top = vector2f(0, 0);
  limit[MODULE_NUCLEAR]->bot = vector2f(400, 300);
  limit[MODULE_FUSION]->top = vector2f(0, 0);
  limit[MODULE_FUSION]->bot = vector2f(550, 320);
  limit[MODULE_CHEST]->top = vector2f(0, 0);
  limit[MODULE_CHEST]->bot = vector2f(130, 75);
  limit[MODULE_LASER]->top = vector2f(-140, -70);
  limit[MODULE_LASER]->bot = vector2f(150, 150);
  limit[11] = NULL;
  return (limit);
}

t_limit		**init_limit()
{
  t_limit	**limit;
  int		i;

  if ((limit = malloc(sizeof(t_limit*) * (NB_LIMIT + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < NB_LIMIT)
    if ((limit[i++] = malloc(sizeof(t_limit))) == NULL)
      return (NULL);
  limit[MODULE_BASE]->top = vector2f(40, BASE_MIN_Y);
  limit[MODULE_BASE]->bot = vector2f(BASE_MAX_X, BASE_MAX_Y);
  limit[MODULE_SOLAR]->top = vector2f(5, 5);
  limit[MODULE_SOLAR]->bot = vector2f(230, 220);
  limit[MODULE_COAL]->top = vector2f(0, 0);
  limit[MODULE_COAL]->bot = vector2f(400, 440);
  limit[MODULE_LAUNCHER]->top = vector2f(30, 30);
  limit[MODULE_LAUNCHER]->bot = vector2f(580, 440);
  limit = init_limit_click(limit);
  return (limit);
}

t_placed_mod	*init_placed(t_config *config)
{
  t_placed_mod	*placed;

  if ((placed = malloc(sizeof(t_placed_mod))) == NULL)
    return (NULL);
  placed = NULL;
  placed = add_to_placed(vector2i(((config->map_size_x / 2)
                                   * SPRITE_FLOOR_SIZE) - (BASE_X / 2),
                                  ((config->map_size_y / 2)
                                   * SPRITE_FLOOR_SIZE) - (BASE_Y / 2)),
                         vector2i(0, 0), 0, placed);
  return (placed);
}
