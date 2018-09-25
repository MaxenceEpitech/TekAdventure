/*
** effect_intro.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Oct 13 10:01:41 2017 maxence.fourrier
** Last update Fri Oct 13 10:18:44 2017 maxence.fourrier
*/

#include "explo.h"

void		wait_end_crash(t_explo *explo)
{
  while (sfMusic_getStatus(explo->music[SND_CRASH]) != sfStopped)
    {
      draw_black(explo);
      sfRenderWindow_display(explo->graph->window);
      if (get_event() == ESCAPE
	  && !wait_key(explo->graph->window, sfKeyEscape))
	break;
    }
}

void		effect_intro(t_explo *explo, int image)
{
  if (image == 160)
    sfMusic_play(explo->music[SND_INC]);
  if (image == 200)
    sfMusic_play(explo->music[SND_EVACUATE]);
  if (image == 305)
    sfMusic_play(explo->music[SND_BFR_SIREN]);
  if (image == 240)
    sfMusic_play(explo->music[SND_DESTROY]);
  if (image == 375)
    sfMusic_play(explo->music[SND_SIREN]);
  if (image == 440)
    wait_end_crash(explo);
  if (image == 439)
    {
      sfMusic_stop(explo->music[SND_SIREN]);
      sfMusic_play(explo->music[SND_CRASH]);
    }
}

