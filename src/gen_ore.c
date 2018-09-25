/*
** gen_ore.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct  6 17:26:10 2017 maxence.fourrier
** Last update Sun Oct  8 23:03:22 2017 jean-baptiste
*/

#include "explo.h"

char		**gen_ore_other(char **ore, sfVector2i size)
{
  if ((ore = gen_filament(ore, size, vector2i(size.x * size.y
					      * PERCENT_URANIUM,
					      URANIUM),
			  vector2i(URANIUM_MIN, URANIUM_MAX))) == NULL
      || (ore = gen_filament(ore, size, vector2i(size.x * size.y
                                                 * PERCENT_IRIDIUM,
                                                 IRIDIUM),
                             vector2i(IRIDIUM_MIN, IRIDIUM_MAX))) == NULL
      || (ore = gen_filament(ore, size, vector2i(size.x * size.y
                                                 * PERCENT_IRON,
                                                 IRON),
                             vector2i(IRON_MIN, IRON_MAX))) == NULL)
    return (NULL);
  return (ore);
}

char		**gen_ore(char **ore, sfVector2i size)
{
  if ((ore = gen_filament(ore, size, vector2i(size.x * size.y
                                              * PERCENT_COPPER,
                                              COPPER),
                          vector2i(COPPER_MIN, COPPER_MAX))) == NULL
      || (ore = gen_filament(ore, size, vector2i(size.x * size.y
                                                 * PERCENT_LITHIUM,
                                                 LITHIUM),
                             vector2i(LITHIUM_MIN, LITHIUM_MAX))) == NULL
      || (ore = gen_filament(ore, size, vector2i(size.x * size.y
                                                 * PERCENT_TITANIUM,
                                                 TITANIUM),
                             vector2i(TITANIUM_MIN, TITANIUM_MAX))) == NULL
      || (ore = gen_filament(ore, size, vector2i(size.x * size.y
                                                 * PERCENT_COAL,
                                                 COAL),
                             vector2i(COAL_MIN, COAL_MAX))) == NULL
      || (ore = gen_ore_other(ore, size)) == NULL)
    return (NULL);
  return (ore);
}
