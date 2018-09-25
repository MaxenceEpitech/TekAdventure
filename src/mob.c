/*
** mob.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct  5 09:46:16 2017 maxence.fourrier
** Last update Wed Oct 11 10:43:35 2017 maxence.fourrier
*/

#include "explo.h"

sfSprite	**init_mob_front(char *str)
{
  sfSprite	**gif;
  int		i;
  int		nb;

  if ((gif = malloc(sizeof(sfSprite *) * 70)) == NULL)
    return (NULL);
  nb = -1;
  i = 115;
  while (i != 52)
    {
      if (i == 126)
        i = 0;
      if ((gif[++nb]
	   = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
				  ".png"))) == NULL)
        return (NULL);
      i++;
    }
  gif[nb] = NULL;
  return (gif);
}

sfSprite	**init_mob_back(char *str)
{
  sfSprite	**gif;
  int		i;
  int		nb;

  if ((gif = malloc(sizeof(sfSprite *) * 70)) == NULL)
    return (NULL);
  nb = -1;
  i = 114;
  while (i != 51)
    {
      if ((gif[++nb] = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
                                            ".png"))) == NULL)
        return (NULL);
      i--;
    }
  gif[nb] = NULL;
  return (gif);
}

t_mob		**init_mob()
{
  t_mob		**mob;
  int		i;

  if ((mob = malloc(sizeof(t_mob *) * (NB_MOB + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < NB_MOB)
    {
      if ((mob[i] = malloc(sizeof(t_mob))) == NULL)
	return (NULL);
      mob[i]->type = -1;
      mob[i]->pos = vector2f(0, 0);
      mob[i]->hp = 100;
      mob[i]->draw = 0;
      mob[i]->draw_ = 0;
      mob[i]->splash = 0;
    }
  mob[i] = NULL;
  return (mob);
}

void		create_mob(t_explo *explo, sfVector2i pos, int amount,
			   int type)
{
  int		i;

  i = -1;
  while (explo->game->mob[++i] && explo->game->mob[i]->type == -1);
  if (explo->game->mob[i] == NULL)
    return ;
  explo->game->mob[i]->type = type;
  explo->game->mob[i]->pos = gen_obj_pos(explo->player->pos);
  explo->game->mob[i]->hp = 100 * (explo->config->difficulty + 1);
}

void		move_mob(sfVector2f player, t_mob *mob)
{
  int		dist;
  sfVector2f	dir;

  dist = get_dist_btw(player, mob->pos);
  if (dist != 0)
    {
      dir.x = (player.x - mob->pos.x) / dist;
      dir.y = (player.y - mob->pos.y) / dist;
    }
  else
    dir = vector2f(0, 0);
  mob->pos.x += dir.x / 2;
  mob->pos.y += dir.y / 2;
}
