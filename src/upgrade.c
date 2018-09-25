/*
** upgrade.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 17:41:36 2017 maxence.fourrier
** Last update Wed Sep 27 19:47:22 2017 maxence.fourrier
*/

#include "explo.h"

int		**create_upgrade_base()
{
  int		**base;

  if ((base = malloc(sizeof(int **) * MAX_UPGRADE)) == NULL
      || (base[0] = first_upgrade_base()) == NULL
      || (base[1] = second_upgrade_base()) == NULL
      || (base[2] = third_upgrade_base()) == NULL)
      return (NULL);
  base[3] = NULL;
  return (base);
}

int		**create_upgrade_solar()
{
  int		**solar;

  if ((solar = malloc(sizeof(int **) * MAX_UPGRADE)) == NULL
      || (solar[0] = first_upgrade_solar()) == NULL
      || (solar[1] = second_upgrade_solar()) == NULL
      || (solar[2] = third_upgrade_solar()) == NULL)
    return (NULL);
  solar[3] = NULL;
  return (solar);
}

int		***init_upgrade()
{
  int		***upgrade;

  if ((upgrade = malloc(sizeof(int ***) * 10)) == NULL
      || (upgrade[MODULE_BASE] = create_upgrade_base()) == NULL
      || (upgrade[MODULE_SOLAR] = create_upgrade_solar()) == NULL)
    return (NULL);
  upgrade[2] = NULL;
  return (upgrade);
}
