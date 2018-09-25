/*
** time.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep 11 17:54:02 2017 maxence.fourrier
** Last update Fri Oct  6 19:13:00 2017 maxence.fourrier
*/

#include <sys/time.h>
#include "explo.h"

unsigned long long	get_time()
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  return ((unsigned long long)(tv.tv_sec) * 1000 +
	  (unsigned long long)(tv.tv_usec) / 1000);
}
