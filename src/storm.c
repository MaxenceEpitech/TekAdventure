/*
** storm.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Oct  3 17:13:54 2017 maxence.fourrier
** Last update Fri Oct 13 13:30:53 2017 maxence.fourrier
*/

#include "explo.h"

t_storm		*init_storm()
{
  t_storm	*storm;
  int		i;

  if ((storm = malloc(sizeof(t_storm))) == NULL
      || (storm->obj = malloc(sizeof(t_obj *) * (NB_MAX_OBJ + 1))) == NULL)
    return (NULL);
  storm->time = get_time()
    + (my_rand(MIN_TIME_STORM, MAX_TIME_STORM) * 1000);
  storm->on = 0;
  storm->time_left = STORM_DURING_TIME;
  i = -1;
  while (++i < NB_MAX_OBJ)
    {
      if ((storm->obj[i] = malloc(sizeof(t_obj))) == NULL)
	return (NULL);
      storm->obj[i]->alive = 0;
      storm->obj[i]->pos = vector2f(0, 0);
      storm->obj[i]->dir = vector2f(0, 0);
      storm->obj[i]->cpt = 0;
    }
  storm->obj[i] = NULL;
  return (storm);
}

void		check_dist_storm(t_explo *explo, t_storm *storm)
{
  int		i;
  int		dist;

  i = -1;
  while (storm->obj[++i])
    if (storm->obj[i]->alive)
      {
	dist = get_dist_btw(explo->player->pos,
			    storm->obj[i]->pos);
	if (dist > 1000)
	  storm->obj[i]->alive = 0;
	else if (dist < 120)
	  {
	    effect_dmg(explo);
	    explo->player->hp -= 0.4 * (1 - ((float)dist / 120));
	    draw_hp(explo);
	  }
      }
}

void		storm(t_explo *explo)
{
  check_dist_storm(explo, explo->game->storm);
  draw_storm(explo, explo->game->storm);
  if (explo->game->time > explo->game->storm->time
      && explo->config->storm == 1)




    explo->game->storm->on = 1;
}

void		do_storm(t_explo *explo)
{
  if (explo->game->storm->on == 1
      && explo->game->storm->time_left <= 0)
    {
      explo->game->storm->time = get_time()
	+ (my_rand(MIN_TIME_STORM, MAX_TIME_STORM) * 1000);
      explo->game->storm->on = 0;
      explo->game->storm->time_left = STORM_DURING_TIME;
    }
  if (explo->game->storm->on == 1)
    {
      if (my_rand(0, 100) <= PERCENT_ADD_OBJ)
	create_storm_obj(explo, explo->game->storm,
			 my_rand(MIN_GEN_OBJ, MAX_GEN_OBJ));
      explo->game->storm->time_left--;
    }
}
