/*
** change_time.c for tekadventure in /home/jean-baptiste/Projets/Semestre2/Graphical/tekadventure/jb_detection
** 
** Made by jean-baptiste
** Login   <jean-baptiste.melet@epitech.eu>
** 
** Started on  Fri Sep 29 14:02:34 2017 jean-baptiste
** Last update Wed Oct 11 17:17:26 2017 maxence.fourrier
*/

#include <string.h>
#include "explo.h"

int		verif_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i] != NULL);
  if (i != 2)
    return (1);
  i = 0;
  while (tab[1][i] != '\0')
    {
      if ((tab[1][i] < '0' || tab[1][i] > '9') && (tab[1][i] != ':'))
        return (1);
      i += 1;
    }
  return (SUCCESS);
}

int		check_hour_console(int hour)
{
  if (hour > NB_HOUR || hour <= 0)
    {
      my_putstr("Please enter a valid hour.\n");
      my_putstr("Your hour must be contain between 1h and ");
      my_putnbr(NB_HOUR);
      my_putstr(".\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int		check_minute_console(int minute)
{
  if ((minute > NB_MINUTE) || (minute < 0))
    {
      my_putstr("Please enter a valid minute.\n");
      my_putstr("Your minute must be contain between 0m and ");
      my_putnbr(NB_MINUTE);
      my_putstr(".\n");
      return (ERROR);
    }
  return (SUCCESS);
}

int		change_time(char **tab, t_explo *explo)
{
  int		new_minute;
  int		new_hour;
  char		*str;
  int		i;

  if (verif_tab(tab) == 1)
    return (SUCCESS);
  if ((str = malloc(sizeof(char) * (my_strlen(tab[1])) + 1)) == NULL)
    return (SUCCESS);
  i = -1;
  while (tab[1][++i] != '\0')
    str[i] = tab[1][i];
  str[i] = '\0';
  if ((new_hour = atoi(str)) == ERROR
      || check_hour_console(new_hour) == ERROR)
    return (SUCCESS);
  str = strstr(tab[1], ":");
  new_minute = atoi(str);
  if (check_minute_console(new_minute) == ERROR)
    return (SUCCESS);
  explo->day->day = new_hour;
  explo->day->minute = new_minute;
  return (SUCCESS);
}
