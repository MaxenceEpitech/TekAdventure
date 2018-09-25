/*
** draw_detail.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 13 12:38:47 2017 maxence.fourrier
** Last update Sun Oct  8 10:59:42 2017 maxence.fourrier
*/

#include <math.h>
#include "explo.h"

void		change_sprite_perso(t_explo *explo)
{
  double	angle;
  int		sprite;

  angle = atan2(explo->player->dir.y,
		explo->player->dir.x) / M_PI * 180;
  if (angle > 0)
    {
      sprite = angle / 180 * (234 / 2);
      if (sprite > 114 || sprite < 0)
	sprite = 114;
      explo->player->draw = vector2i(0, sprite);
    }
  if (angle <= 0)
    {
      sprite = angle / 180 * (234 / 2) * -1;
      if (sprite > 114 || sprite < 0)
	sprite = 114;
      explo->player->draw = vector2i(1, sprite);
    }
}

int		draw_perso(t_explo *explo)
{
  sfVector2f	vec;

  if (explo->player->dir.x != 0
      && explo->player->dir.y != 0)
    change_sprite_perso(explo);
  vec = vector2f(explo->player->pos.x - PERSO_SIZE_X,
		 explo->player->pos.y - PERSO_SIZE_Y);
  if (explo->player->draw.x == 0)
    {
      sfSprite_setPosition(explo->player->front_player
			   [explo->player->draw.y], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->player->front_player
				[explo->player->draw.y], NULL);
    }
  else
    {
      sfSprite_setPosition(explo->player->back_player
			   [explo->player->draw.y], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->player->back_player
				[explo->player->draw.y], NULL);
    }
  return (SUCCESS);
}

int		draw_home(t_explo *explo)
{
  if (get_dist_btw(vector2f(((explo->game->size.x / 2)
			     * SPRITE_FLOOR_SIZE) - (BASE_X / 2),
			    ((explo->game->size.y / 2)
			     * SPRITE_FLOOR_SIZE) - (BASE_Y / 2)),
		   explo->player->pos) > 2000)
    return (SUCCESS);
  sfRenderWindow_drawCircleShape(explo->graph->window,
				 explo->circle[0], NULL);
  return (SUCCESS);
}

int		draw_click(t_explo *explo)
{
  if (explo->player->dir.x == 0 && explo->player->dir.y == 0)
    return (SUCCESS);
  sfSprite_setPosition(explo->sprite[SPR_CLICK], vector2f
		       (explo->player->click.x - CLICK_SIZE / 2,
			explo->player->click.y - CLICK_SIZE / 2));
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[SPR_CLICK], NULL);
  return (SUCCESS);
}
