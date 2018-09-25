/*
** init_player.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep  8 19:33:29 2017 maxence.fourrier
** Last update Thu Oct 12 10:48:23 2017 maxence.fourrier
*/

#include "explo.h"

sfSprite	**init_player_front(char *str)
{
  sfSprite	**gif;
  int		i;
  int		nb;

  if ((gif = malloc(sizeof(sfSprite *) * 121)) == NULL)
    return (NULL);
  nb = -1;
  i = 60;
  while (i != 178)
    {
      if (i == 0)
	i = 234;
      if ((gif[++nb] = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
					    ".png"))) == NULL)
        return (NULL);
      i--;
    }
  gif[nb] = NULL;
  return (gif);
}

sfSprite	**init_player_back(char *str)
{
  sfSprite	**gif;
  int		i;
  int		nb;

  if ((gif = malloc(sizeof(sfSprite *) * 121)) == NULL)
    return (NULL);
  nb = -1;
  i = 60;
  while (i != 177)
    {
      if ((gif[++nb] = load_picture(new_cat(new_cat(str, my_int_to_str(i)),
					    ".png"))) == NULL)
        return (NULL);
      i++;
    }
  gif[nb] = NULL;
  return (gif);
}

t_player	*init_player_other(t_player *player, t_config *config)
{
  player->power = config->player_power;
  player->speed = config->player_speed;
  player->base_power = 1000;
  player->draw = vector2i(0, 0);
  player->inv[0][0]->item = MODULE_DRILL + 19;
  player->inv[0][0]->quantity = 1;
  return (player);
}

t_player	*init_player(t_config *config)
{
  t_player	*player;

  if ((player = malloc(sizeof(t_player))) == NULL
      || (player->inv = init_inv()) == NULL)
    return (NULL);
  player->pos = vector2f((double)((config->map_size_y / 2)
				  * SPRITE_FLOOR_SIZE),
			 (double)((config->map_size_x / 2 + BORDER)
				  * SPRITE_FLOOR_SIZE));
  player->click = vector2i(player->pos.x, player->pos.y);
  player->dir = vector2f(0, 0);
  player->oxy = config->player_oxy;
  player->cons_oxy = MAX_DIFFICULTY / config->difficulty;
  player->hp = config->player_hp;
  player->reg_hp = MAX_DIFFICULTY / config->difficulty;
  if ((player->front_player = init_player_front(GIF_12_NAME)) == NULL
      || (player->back_player
	  = init_player_back(GIF_12_NAME)) == NULL
      || (player = init_player_other(player, config)) == NULL)
    return (NULL);
  return (player);
}

t_inv		***init_inv()
{
  t_inv		***inv;
  int		y;
  int		x;

  if ((inv = malloc(sizeof(t_inv **) * (SIZE_INV_Y + 2))) == NULL)
    return (NULL);
  y = 0;
  while (y < SIZE_INV_Y + 1)
    {
      x = 0;
      if ((inv[y] = malloc(sizeof(t_inv *) * (SIZE_INV_X + 1))) == NULL)
        return (NULL);
      while (x < SIZE_INV_X)
        {
	  if ((inv[y][x] = malloc(sizeof(t_inv))) == NULL)
	    return (NULL);
          inv[y][x]->item = -1;
          inv[y][x]->quantity = -1;
          x++;
        }
      inv[y][x] = NULL;
      y++;
    }
  inv[y] = NULL;
  return (inv);
}
