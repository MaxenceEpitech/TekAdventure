/*
** draw_mob.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Oct  7 22:14:13 2017 maxence.fourrier
** Last update Fri Oct 13 13:32:33 2017 maxence.fourrier
*/

#include <math.h>
#include "explo.h"

void		draw_mob_dir(t_explo *explo, t_mob *mob,
			     sfVector2f dir)
{
  double	angle;
  int		sprite;

  angle = atan2(dir.y, dir.x) / M_PI * 180;
  if (angle > 0)
    {
      sprite = angle / 180 * (125 / 2);
      if (sprite > 61 || sprite < 0)
        sprite = 61;
      sfSprite_setPosition(explo->game->front_mob[sprite],
			   vector2f(mob->pos.x - 70, mob->pos.y - 70));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->game->front_mob[sprite], NULL);
    }
  if (angle <= 0)
    {
      sprite = angle / 180 * (125 / 2) * -1;
      if (sprite > 61 || sprite < 0)
        sprite = 61;
      sfSprite_setPosition(explo->game->back_mob[sprite],
			   vector2f(mob->pos.x - 70, mob->pos.y - 70));
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->game->back_mob[sprite], NULL);
    }
}

void		draw_mob_before_type(t_explo *explo, t_mob *mob)
{
  int		dist;
  sfVector2f	dir;

  if ((dist = get_dist_btw(explo->player->pos, mob->pos)) != 0)
    {
      dir.x = (explo->player->pos.x - mob->pos.x) / dist;
      dir.y = (explo->player->pos.y - mob->pos.y) / dist;
    }
  else
    dir = vector2f(0, 0);
  draw_mob_dir(explo, mob, dir);
  if (dist > 80 && dist < 800)
    move_mob(explo->player->pos, mob);
  else if (dist <= 80)
    {
      if (explo->player->hp > 0)
	{
	  effect_dmg(explo);
	  explo->player->hp -= 0.1;
	}
      draw_hp(explo);
    }
}

void		draw_bird(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i])
    if (explo->game->mob[i]->type >= 1
	&& explo->game->mob[i]->splash
	>= (GIF_17_TIME - 1) * (GIF_17_TOTAL - 1))
      draw_mob_before_type(explo, explo->game->mob[i]);
    else if (explo->game->mob[i]->type >= 1
	     && explo->game->mob[i]->splash
	     <= (GIF_17_TIME - 1) * (GIF_17_TOTAL - 1))
      {
	sfSprite_setPosition(explo->gif[GIF_17]
			     [explo->game->mob[i]->splash / GIF_17_TIME],
                             vector2f(explo->game->mob[i]->pos.x - 100,
				      explo->game->mob[i]->pos.y - 100));
        sfRenderWindow_drawSprite(explo->graph->window,
                                  explo->gif[GIF_17]
				  [explo->game->mob[i]->splash / GIF_17_TIME],
				  NULL);
	explo->game->mob[i]->splash++;
      }
}

void		draw_egg_before(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i])
    if (explo->game->mob[i]->type == 0
	&& explo->game->mob[i]->pos.y - 20
	<= explo->player->pos.y)
      draw_gif_mob(explo, explo->game->mob[i],
                   vector3f(explo->game->mob[i]->pos.x,
                            explo->game->mob[i]->pos.y, GIF_13),
                   vector2i(GIF_13_TOTAL, GIF_13_TIME));
}

void		draw_egg_after(t_explo *explo)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i])
    {
      if (explo->game->mob[i]->draw_ == 0 && explo->game->mob[i]->type == 0)
        draw_gif_mob(explo, explo->game->mob[i],
                     vector3f(explo->game->mob[i]->pos.x,
                              explo->game->mob[i]->pos.y, GIF_13),
                     vector2i(GIF_13_TOTAL, GIF_13_TIME));
      explo->game->mob[i]->draw_ = 0;
    }
}
