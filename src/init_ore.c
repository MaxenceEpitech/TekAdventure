/*
** init_ore.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 13 21:44:22 2017 maxence.fourrier
** Last update Fri Oct  6 17:57:27 2017 maxence.fourrier
*/

#include "explo.h"

sfVector2i	gen_init_pos_filament(char **ore, sfVector2i size,
				      int id)
{
  sfVector2i	pos;

  pos = vector2i(my_rand(ORE_BORDER, size.x - ORE_BORDER),
		 my_rand(ORE_BORDER, size.y - ORE_BORDER));
  while (init_ore_is_unvalide(ore, pos))
    pos = vector2i(my_rand(ORE_BORDER, size.x - ORE_BORDER),
		   my_rand(ORE_BORDER, size.y - ORE_BORDER));
  ore[pos.y][pos.x] = id;
  return (pos);
}

void		gen_other_filament(char **ore, sfVector2i size,
				   sfVector2i init_pos, int id)
{
  sfVector2i	pos;

  pos = vector2i(my_rand(init_pos.x - ORE_GEN_CIRCLE,
			 init_pos.x + ORE_GEN_CIRCLE),
		 my_rand(init_pos.y - ORE_GEN_CIRCLE,
			 init_pos.y + ORE_GEN_CIRCLE));
  while (gen_pos_is_unvalide(pos, size, ore, id))
    pos = vector2i(my_rand(init_pos.x - ORE_GEN_CIRCLE,
			   init_pos.x + ORE_GEN_CIRCLE),
		   my_rand(init_pos.y - ORE_GEN_CIRCLE,
			   init_pos.y + ORE_GEN_CIRCLE));
  ore[pos.y][pos.x] = id;
}

char		**gen_filament(char **ore, sfVector2i size,
			       sfVector2i info, sfVector2i limit)
{
  sfVector2i	init_pos;
  int		size_filament;
  int		nb_total;

  nb_total = 0;
  while (nb_total < info.x)
    {
      size_filament = my_rand(limit.x, limit.y);
      nb_total += size_filament;
      init_pos = gen_init_pos_filament(ore, size, info.y);
      while (size_filament > 0)
	{
	  gen_other_filament(ore, size, init_pos, info.y);
	  size_filament--;
	}
    }
  return (ore);
}

char		***init_ore(t_config *config)
{
  char		***ore;
  int		i;
  int		cpt;

  if ((ore = malloc(sizeof(char**) * (ORE_HEIGHT + 1))) == NULL)
    return (NULL);
  cpt = -1;
  while (++cpt < ORE_HEIGHT)
    {
      if ((ore[cpt] = malloc(sizeof(char*)
			     * (config->map_size_y + 1))) == NULL)
	return (NULL);
      i = -1;
      while (++i < config->map_size_y)
	if ((ore[cpt][i] = malloc(sizeof(char)
				  * (config->map_size_x + 1))) == NULL)
	  return (NULL);
      ore[cpt] = fill_map_c(config, ore[cpt]);
      if ((ore[cpt] = gen_ore(ore[cpt],
			      vector2i(config->map_size_x,
				       config->map_size_y))) == NULL)
	return (NULL);
    }
  ore[cpt] = NULL;
  return (ore);
}
