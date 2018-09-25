/*
** mob_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct  7 11:02:15 2017 maxence.fourrier
** Last update Sat Oct  7 20:42:39 2017 maxence.fourrier
*/

#include "explo.h"

void		draw_gif_mob(t_explo *explo, t_mob *mob,
			     sfVector3f pos, sfVector2i gif)
{
  int		nb;

  if (mob->draw == gif.x * gif.y)
    mob->draw = 0;
  nb = mob->draw / gif.y;
  sfSprite_setPosition(explo->gif[(int)pos.z][nb],
		       vector2f(pos.x - 50, pos.y - 50));
  sfRenderWindow_drawSprite(explo->graph->window,
                            explo->gif[(int)pos.z][nb], NULL);
  mob->draw = mob->draw + 1;
  mob->draw_ = 1;
}

int		nb_egg_around_player(t_explo *explo)
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (explo->game->mob[++i])
    if (explo->game->mob[i]->type == 0
	&& explo->game->mob[i]->pos.x
	>= explo->player->pos.x - (8 * SPRITE_FLOOR_SIZE)
	&& explo->game->mob[i]->pos.x
	< explo->player->pos.x + (8 * SPRITE_FLOOR_SIZE)
	&& explo->game->mob[i]->pos.y
	>= explo->player->pos.y - (8 * SPRITE_FLOOR_SIZE)
	&& explo->game->mob[i]->pos.y
	< explo->player->pos.y + (8 * SPRITE_FLOOR_SIZE))
      nb++;
  return (nb);
}

sfVector2f	gen_egg(t_explo *explo)
{
  sfVector2f	pos;

  pos.x = my_rand(explo->player->pos.x - (8 * SPRITE_FLOOR_SIZE),
		  explo->player->pos.x + (8 * SPRITE_FLOOR_SIZE));
  pos.y = my_rand(explo->player->pos.y - (8 * SPRITE_FLOOR_SIZE),
		  explo->player->pos.y + (7 * SPRITE_FLOOR_SIZE));
  while ((pos.x >= explo->player->pos.x - (4 * SPRITE_FLOOR_SIZE)
          && pos.x < explo->player->pos.x + (2.5 * SPRITE_FLOOR_SIZE)
          && pos.y >= explo->player->pos.y - (4 * SPRITE_FLOOR_SIZE)
          && pos.y < explo->player->pos.y + (2.5 * SPRITE_FLOOR_SIZE)))
    {
      pos.x = my_rand(explo->player->pos.x - (8 * SPRITE_FLOOR_SIZE),
		      explo->player->pos.x + (8 * SPRITE_FLOOR_SIZE));
      pos.y = my_rand(explo->player->pos.y - (8 * SPRITE_FLOOR_SIZE),
		      explo->player->pos.y + (8 * SPRITE_FLOOR_SIZE));
    }
  return (pos);
}

void		add_to_egg(t_explo *explo, sfVector2f pos)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i])
    if (explo->game->mob[i]->type == -1)
      {
	explo->game->mob[i]->type = 0;
	explo->game->mob[i]->pos.x = pos.x;
	explo->game->mob[i]->pos.y = pos.y;
	break;
      }
}

void		gen_mob(t_explo *explo)
{
  int		nb;
  sfVector2f	egg_pos;

  explo->game->spawn_mob = explo->game->time;
  if (explo->day->day > NB_HOUR / 2
      && explo->day->day <= NB_HOUR)
    {
      nb = nb_egg_around_player(explo);
      while (nb < 15)
	{
	  egg_pos = gen_egg(explo);
	  add_to_egg(explo, egg_pos);
	  nb++;
	}
    }
}
