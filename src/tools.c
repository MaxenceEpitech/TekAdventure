/*
** tools.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 09:46:56 2017 maxence.fourrier
** Last update Mon Oct  9 19:12:43 2017 maxence.fourrier
*/

#include <math.h>
#include "explo.h"

int		use_food(t_explo *explo, sfVector2i pos)
{
  explo->player->inv[pos.y][pos.x]->quantity--;
  if (explo->player->inv[pos.y][pos.x]->quantity <= 0)
    {
      explo->player->inv[pos.y][pos.x]->item = -1;
      explo->player->inv[pos.y][pos.x]->quantity = -1;
    }
  explo->player->hp += FOOD_HEAL;
  return (1);
}

int		get_dist_btw(sfVector2f a, sfVector2f b)
{
  int		ret;

  ret = sqrt(((a.x - b.x) * (a.x - b.x))
	     + ((a.y - b.y) * (a.y - b.y)));
  return (ret);
}

int		my_rand(int min, int max)
{
  return (rand() % (max - min + 1) + min);
}

sfSprite	*load_picture(char *str)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((texture = sfTexture_createFromFile(str, NULL)) == NULL)
    {
      if ((sprite = sfSprite_create()) == NULL)
	return (NULL);
      sfSprite_setColor(sprite, sfBlue);
      return (sprite);
    }
  if ((sprite = sfSprite_create()) == NULL)
    return (NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}
