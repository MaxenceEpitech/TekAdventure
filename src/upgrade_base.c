/*
** upgrade_base.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 27 19:25:01 2017 maxence.fourrier
** Last update Wed Sep 27 19:28:07 2017 maxence.fourrier
*/

#include "explo.h"

int		*first_upgrade_base()
{
  int		*base;

  if ((base = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  base[COAL - '0'] = 1;
  base[IRON - '0'] = 0;
  base[COPPER - '0'] = 0;
  base[LITHIUM - '0'] = 0;
  base[URANIUM - '0'] = 0;
  base[TITANIUM - '0'] = 0;
  base[IRIDIUM - '0'] = 0;
  base[CARBON - '0'] = 0;
  base[GLASS - '0'] = 0;
  base[9] = -1;
  return (base);
}

int		*second_upgrade_base()
{
  int		*base;

  if ((base = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  base[COAL - '0'] = 2;
  base[IRON - '0'] = 0;
  base[COPPER - '0'] = 0;
  base[LITHIUM - '0'] = 0;
  base[URANIUM - '0'] = 0;
  base[TITANIUM - '0'] = 0;
  base[IRIDIUM - '0'] = 0;
  base[CARBON - '0'] = 0;
  base[GLASS - '0'] = 0;
  base[9] = -1;
  return (base);
}

int		*third_upgrade_base()
{
  int		*base;

  if ((base = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  base[COAL - '0'] = 3;
  base[IRON - '0'] = 0;
  base[COPPER - '0'] = 0;
  base[LITHIUM - '0'] = 0;
  base[URANIUM - '0'] = 0;
  base[TITANIUM - '0'] = 0;
  base[IRIDIUM - '0'] = 0;
  base[CARBON - '0'] = 0;
  base[GLASS - '0'] = 0;
  base[9] = -1;
  return (base);
}
