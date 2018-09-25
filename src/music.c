/*
** music.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 21:50:31 2017 maxence.fourrier
** Last update Fri Oct 13 13:31:51 2017 maxence.fourrier
*/

#include "explo.h"

void		music_game(t_explo *explo)
{
  if (sfMusic_getStatus(explo->music[explo->game->music]) == sfStopped)
    {
      explo->game->music++;
      if (explo->game->music > 8)
	explo->game->music = 1;
      play_stop_music(explo, vector2i(1, explo->game->music),
		      vector2i(0, 0), 0);
    }
}

void		play_stop_music(t_explo *explo, sfVector2i play,
				sfVector2i stop, int loop)
{
  if (play.x == 1)
    sfMusic_play(explo->music[play.y]);
  if (loop == 1 && play.x == 1)
    sfMusic_setLoop(explo->music[play.y], sfTrue);
  else if (play.x == 1)
    sfMusic_setLoop(explo->music[play.y], sfFalse);
  if (stop.x == 1)
    sfMusic_stop(explo->music[stop.y]);
}

void		effect_dmg(t_explo *explo)
{
  int		nb;

  if (sfMusic_getStatus(explo->music[SND_INJ1]) != sfStopped
      || sfMusic_getStatus(explo->music[SND_INJ2]) != sfStopped
      || sfMusic_getStatus(explo->music[SND_INJ3]) != sfStopped)
    return ;
  nb = my_rand(1, 3);
  if (nb == 1)
    sfMusic_play(explo->music[SND_INJ1]);
  if (nb == 2)
    sfMusic_play(explo->music[SND_INJ2]);
  if (nb == 3)
    sfMusic_play(explo->music[SND_INJ3]);
}
