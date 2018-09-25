/*
** close_free.c for tekadvendture in /home/camille/semestre2/tekadventure
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Thu Aug 17 17:24:12 2017 camille
** Last update Sun Oct  8 17:13:58 2017 camille
*/

#include <stdlib.h>
#include "tek.h"

void		destroy_music(sfMusic **music)
{
  sfMusic_destroy(music[0]);
  sfMusic_destroy(music[1]);
  sfMusic_destroy(music[2]);
  sfMusic_destroy(music[3]);
}

void	free_and_quit(t_materials *mats)
{
  int	i;

  i = 0;
  sfRenderWindow_destroy(mats->wdw);
  destroy_music(mats->music);
  free(mats->music);
  while (i < 12)
    {
      sfSprite_destroy(mats->spr[i]);
      sfTexture_destroy(mats->tex[i]);
      i += 1;
    }
  free(mats->tex);
  free(mats->spr);
}
