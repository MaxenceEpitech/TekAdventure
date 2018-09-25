/*
** upgrade_solar.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 25 17:51:18 2017 maxence.fourrier
** Last update Tue Sep 26 10:47:30 2017 maxence.fourrier
*/

#include "explo.h"

int		*first_upgrade_solar()
{
  int		*solar;

  if ((solar = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  solar[COAL - '0'] = 0;
  solar[IRON - '0'] = 0;
  solar[COPPER - '0'] = 1;
  solar[LITHIUM - '0'] = 0;
  solar[URANIUM - '0'] = 0;
  solar[TITANIUM - '0'] = 1;
  solar[IRIDIUM - '0'] = 0;
  solar[CARBON - '0'] = 0;
  solar[GLASS - '0'] = 0;
  solar[9] = -1;
  return (solar);
}

int		*second_upgrade_solar()
{
  int		*solar;

  if ((solar = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  solar[COAL - '0'] = 5;
  solar[IRON - '0'] = 0;
  solar[COPPER - '0'] = 0;
  solar[LITHIUM - '0'] = 0;
  solar[URANIUM - '0'] = 0;
  solar[TITANIUM - '0'] = 0;
  solar[IRIDIUM - '0'] = 0;
  solar[CARBON - '0'] = 0;
  solar[GLASS - '0'] = 0;
  solar[9] = -1;
  return (solar);
}

int		*third_upgrade_solar()
{
  int		*solar;

  if ((solar = malloc(sizeof(int *) * 11)) == NULL)
    return (NULL);
  solar[COAL - '0'] = 0;
  solar[IRON - '0'] = 4;
  solar[COPPER - '0'] = 0;
  solar[LITHIUM - '0'] = 0;
  solar[URANIUM - '0'] = 0;
  solar[TITANIUM - '0'] = 0;
  solar[IRIDIUM - '0'] = 0;
  solar[CARBON - '0'] = 0;
  solar[GLASS - '0'] = 0;
  solar[9] = -1;
  return (solar);
}
