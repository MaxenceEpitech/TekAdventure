/*
** gen_procedural.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
**
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 13 13:32:20 2017 maxence.fourrier
** Last update Sun Oct  8 13:09:12 2017 maxence.fourrier
*/

#include "explo.h"

int		contain_not_gen(int **map)
{
  int		x;
  int		y;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x] != -2)
	{
	  if (map[y][x] == -1)
	    return (1);
	  x++;
	}
      y++;
    }
  return (SUCCESS);
}

sfVector2i	gen_pos_radius(sfVector2i center, int radius)
{
  sfVector2i	new_pos;

  radius = radius / 1.5;
  new_pos.x = rand() % ((center.x + radius) - (center.x - radius) + 1)
    + (center.x - radius);
  new_pos.y = rand() % ((center.y + radius) - (center.y - radius) + 1)
    + (center.y - radius);
  return (new_pos);
}

int		**change_biome(int **map, sfVector2i *pos,
			       sfVector2i radius_biome)
{
  sfVector2i	cpt;
  int		i;

  cpt.y = -1;
  while (map[++cpt.y])
    {
      cpt.x = -1;
      while (map[cpt.y][++cpt.x] != -2)
	{
	  i = -1;
	  while (pos[++i].x != END_LIST_POS)
	    if (cpt.x <= pos[i].x + radius_biome.x
		&& cpt.x >= pos[i].x - radius_biome.x
		&& cpt.y <= pos[i].y + radius_biome.x
		&& cpt.y >= pos[i].y - radius_biome.x
		&& map[cpt.y][cpt.x] == -1)
	      map[cpt.y][cpt.x] = radius_biome.y;
	}
    }
  return (map);
}

int		**gen_biome_part(int biome, int **map, sfVector2i size)
{
  int		radius;
  int		nb_pos;
  sfVector2i	*pos;
  int		i;

  nb_pos = rand() % (M_G_NB_POS_MAX - M_G_NB_POS_MIN + 1)
    + M_G_NB_POS_MIN;
  if ((pos = malloc(sizeof(sfVector2i) * (nb_pos + 1))) == NULL)
    return (NULL);
  radius = rand() % (M_G_R_MAX - M_G_R_MIN + 1) + M_G_R_MIN;
  pos[0] = vector2i(rand() % ((size.x + (M_G_POS_DIFF)) + 1 - (-M_G_POS_DIFF))
		    + (-M_G_POS_DIFF),
		    rand() % ((size.y + (M_G_POS_DIFF)) + 1 - (-M_G_POS_DIFF))
		    + (-M_G_POS_DIFF));
  i = 0;
  while (++i < nb_pos)
    pos[i] = gen_pos_radius(pos[0], radius);
  pos[nb_pos].x = END_LIST_POS;
  map = change_biome(map, pos, vector2i(radius, biome));
  free(pos);
  return (map);
}

int		**gen_biome(int **map, sfVector2i size)
{
  int		biome;

  while (contain_not_gen(map))
    {
      biome = my_rand(0, 2);
      if ((map = gen_biome_part(biome, map, size)) == NULL)
	return (NULL);
    }
  return (map);
}
