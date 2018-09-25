/*
** env.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct  5 13:51:23 2017 maxence.fourrier
** Last update Sun Oct  8 23:34:14 2017 jean-baptiste
*/

#include "explo.h"

sfVector2i	**init_rock_limit()
{
  sfVector2i	**rock;

  if ((rock = malloc(sizeof(sfVector2i **) * 3)) == NULL
      || (rock[0] = malloc(sizeof(sfVector2i *) * 5)) == NULL
      || (rock[1] = malloc(sizeof(sfVector2i *) * 5)) == NULL)
    return (NULL);
  rock[2] = NULL;
  rock[0][0] = vector2i(56, 43);
  rock[1][0] = vector2i(220, 119);
  rock[0][1] = vector2i(59, 54);
  rock[1][1] = vector2i(193, 111);
  rock[0][2] = vector2i(71, 56);
  rock[1][2] = vector2i(256, 149);
  rock[0][3] = vector2i(55, 70);
  rock[1][3] = vector2i(292, 220);
  return (rock);
}

void		change_rock_dir(t_explo *explo, t_pos *rock,
			       sfVector2f pos, sfVector2f dir)
{
  if (pos.x < rock->vec.x * SPRITE_FLOOR_SIZE
      + explo->game->rock_limit[0][rock->type].x
      || pos.x > rock->vec.x * SPRITE_FLOOR_SIZE
      + explo->game->rock_limit[1][rock->type].x)
    explo->player->dir.x = 0;
  if (pos.y < rock->vec.y * SPRITE_FLOOR_SIZE
      + explo->game->rock_limit[0][rock->type].y
      || pos.y > rock->vec.y * SPRITE_FLOOR_SIZE
      + explo->game->rock_limit[1][rock->type].y)
    explo->player->dir.y = 0;
}

void		check_rock_dir(t_explo *explo, t_pos *rock,
			       sfVector2f pos, sfVector2f dir)
{
  while (rock != NULL)
    {
      if (rock->alive == 1
	  && pos.x + dir.x >= rock->vec.x * SPRITE_FLOOR_SIZE
          + explo->game->rock_limit[0][rock->type].x
          && pos.x + dir.x <= rock->vec.x * SPRITE_FLOOR_SIZE
	  + explo->game->rock_limit[1][rock->type].x
          && pos.y + dir.y >= rock->vec.y * SPRITE_FLOOR_SIZE
	  + explo->game->rock_limit[0][rock->type].y
          && pos.y + dir.y <= rock->vec.y * SPRITE_FLOOR_SIZE
	  + explo->game->rock_limit[1][rock->type].y)
	change_rock_dir(explo, rock, pos, dir);
      rock = rock->next;
    }
}

void		draw_env(t_explo *explo)
{
  draw_env_rock(explo, explo->game->rock);
  draw_env_lake(explo, explo->game->mountain);
}

void		draw_env_after_player(t_explo *explo, t_pos *rock)
{
  while (rock != NULL)
    {
      if (rock->alive && rock->draw == 0
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
	}
      rock->draw = 0;
      rock = rock->next;
    }
}
