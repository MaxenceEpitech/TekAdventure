/*
** draw_env.c for draw_env in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct  7 09:27:43 2017 maxence.fourrier
** Last update Sun Oct  8 23:03:04 2017 jean-baptiste
*/

#include "explo.h"

void		draw_env_lake(t_explo *explo, t_pos *lake)
{
  while (lake != NULL)
    {
      if (lake->vec.x * SPRITE_FLOOR_SIZE
          >= explo->player->pos.x - (6 * SPRITE_FLOOR_SIZE)
          && lake->vec.x * SPRITE_FLOOR_SIZE
          < explo->player->pos.x + (4 * SPRITE_FLOOR_SIZE)
          && lake->vec.y * SPRITE_FLOOR_SIZE
          >= explo->player->pos.y - (6 * SPRITE_FLOOR_SIZE)
          && lake->vec.y * SPRITE_FLOOR_SIZE
          < explo->player->pos.y + (2.5 * SPRITE_FLOOR_SIZE))
        {
          sfSprite_setPosition(explo->sprite[SPR_LAKE],
                               vector2f(lake->vec.x * SPRITE_FLOOR_SIZE,
                                        lake->vec.y * SPRITE_FLOOR_SIZE));
          sfRenderWindow_drawSprite(explo->graph->window,
                                    explo->sprite[SPR_LAKE],
                                    NULL);
	}
      lake = lake->next;
    }
}

void		draw_env_rock(t_explo *explo, t_pos *rock)
{
  while (rock != NULL)
    {
      if (rock->alive == 1
          && explo->player->pos.y > rock->vec.y * SPRITE_FLOOR_SIZE
          + (explo->game->rock_limit[1][rock->type].y / 2)
          && rock->vec.x * SPRITE_FLOOR_SIZE
          >= explo->player->pos.x - (4 * SPRITE_FLOOR_SIZE)
          && rock->vec.x * SPRITE_FLOOR_SIZE
          < explo->player->pos.x + (4 * SPRITE_FLOOR_SIZE)
          && rock->vec.y * SPRITE_FLOOR_SIZE
          >= explo->player->pos.y - (2.5 * SPRITE_FLOOR_SIZE)
          && rock->vec.y * SPRITE_FLOOR_SIZE
          < explo->player->pos.y + (2.5 * SPRITE_FLOOR_SIZE))
        {
          sfSprite_setPosition(explo->sprite[SPR_ROCK_0 + rock->type],
                               vector2f(rock->vec.x * SPRITE_FLOOR_SIZE,
                                        rock->vec.y * SPRITE_FLOOR_SIZE));
          sfRenderWindow_drawSprite(explo->graph->window,
                                    explo->sprite[SPR_ROCK_0 + rock->type],
                                    NULL);
          rock->draw = 1;
        }
      rock = rock->next;
    }
}
