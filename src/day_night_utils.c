/*
** day_night_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 24 15:29:30 2017 maxence.fourrier
** Last update Wed Oct 11 15:58:12 2017 maxence.fourrier
*/

#include "explo.h"

t_day		*init_day()
{
  t_day		*day;

  if ((day = malloc(sizeof(t_day))) == NULL)
    return (NULL);
  day->time = get_time();
  day->minute = 0;
  day->day = 1;
  return (day);
}

int		get_hour(t_explo *explo)
{
  int		hour;

  hour = explo->day->day;
  while (((hour + 1) * HOUR) + explo->day->time
         < explo->game->time)
    hour++;
  if (hour >= NB_HOUR)
    {
      explo->day->time = get_time();
      return (SUCCESS);
    }
  return (hour);
}

int		get_minute(t_explo *explo, int hour)
{
  int		minute;

  minute = explo->day->minute;
  while (((minute + 1) * MINUTE) + (HOUR * hour) +
         explo->day->time < explo->game->time)
    minute++;
  if (minute >= NB_MINUTE - 1)
    {
      explo->day->minute = 0;
      return (SUCCESS);
    }
  return (minute);
}
