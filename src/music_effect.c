/*
** music_effect.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct 12 11:13:04 2017 maxence.fourrier
** Last update Fri Oct 13 12:55:04 2017 maxence.fourrier
*/

#include "explo.h"

void		effect_laser(t_explo *explo, int nb)
{
  if (nb == 0)
    sfMusic_play(explo->music[SND_LASER]);
}

void		effect_drill(t_explo *explo)
{
  if (sfMusic_getStatus(explo->music[SND_DRILL_2]) == sfStopped
      && sfMusic_getStatus(explo->music[SND_DRILL_2]) == sfStopped)
    {
      if (my_rand(0, 1))
	sfMusic_play(explo->music[SND_DRILL_1]);
      else
	sfMusic_play(explo->music[SND_DRILL_2]);
    }
}

void		effect_bird(t_explo *explo)
{
  int		nb;

  nb = my_rand(1, 3);
  if (nb == 1)
    sfMusic_play(explo->music[SND_DI1]);
  if (nb == 2)
    sfMusic_play(explo->music[SND_DI2]);
  if (nb == 3)
    sfMusic_play(explo->music[SND_DI3]);
}

void		effect_egg(t_explo *explo)
{
  sfMusic_play(explo->music[SND_EGG_EXPLO]);
}

void		effect_death(t_explo *explo)
{
  int		nb;

  nb = my_rand(1, 3);
  if (nb == 1)
    sfMusic_play(explo->music[SND_DEATH1]);
  if (nb == 2)
    sfMusic_play(explo->music[SND_DEATH2]);
  if (nb == 3)
    sfMusic_play(explo->music[SND_DEATH3]);  
}
