/*
** music_module.c for tekadv in /home/maxence.fourrier/tekadventure/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct 11 17:03:33 2017 maxence.fourrier
** Last update Wed Oct 11 19:32:02 2017 maxence.fourrier
*/

#include "explo.h"

void		music_coal(t_explo *explo, t_placed_mod *placed)
{
  music_game(explo);
  if ((placed->furnace.x == 1 || placed->furnace.y == 1)
      && sfMusic_getStatus(explo->music[SND_COAL]) == sfStopped)
    play_stop_music(explo, vector2i(1, SND_COAL),
		    vector2i(0, 0), 0);
  if (placed->furnace.x == 0 && placed->furnace.y == 0
      && sfMusic_getStatus(explo->music[SND_COAL]) == sfPlaying)
    play_stop_music(explo, vector2i(0, 0),
		    vector2i(1, SND_COAL), 0);
}

void		music_solar(t_explo *explo, t_placed_mod *placed)
{
  music_game(explo);
  if (placed->on == 1 && placed->link == 1
      && sfMusic_getStatus(explo->music[SND_SOLAR]) == sfStopped)
    play_stop_music(explo, vector2i(1, SND_SOLAR),
		    vector2i(0, 0), 0);
  if (placed->on == 0 || placed->link == 0
      && sfMusic_getStatus(explo->music[SND_SOLAR]) == sfPlaying)
    play_stop_music(explo, vector2i(0, 0),
		    vector2i(1, SND_SOLAR), 0);
}

void		music_nuclear(t_explo *explo, t_placed_mod *placed)
{
  music_game(explo);
  if ((placed->furnace.x == 1 || placed->furnace.y == 1)
      && sfMusic_getStatus(explo->music[SND_NUCLEAR]) == sfStopped)
    play_stop_music(explo, vector2i(1, SND_NUCLEAR),
		    vector2i(0, 0), 0);
  if (placed->furnace.x == 0 && placed->furnace.y == 0
      && sfMusic_getStatus(explo->music[SND_NUCLEAR]) == sfPlaying)
    play_stop_music(explo, vector2i(0, 0),
		    vector2i(1, SND_NUCLEAR), 0);
}

void		music_fusion(t_explo *explo, t_placed_mod *placed)
{
  music_game(explo);
  if ((placed->furnace.x == 1
       && sfMusic_getStatus(explo->music[SND_FUSION]) == sfStopped))
    play_stop_music(explo, vector2i(1, SND_FUSION),
		    vector2i(0, 0), 0);
  if (placed->furnace.x == 0
      && sfMusic_getStatus(explo->music[SND_FUSION]) == sfPlaying)
    play_stop_music(explo, vector2i(0, 0),
		    vector2i(1, SND_FUSION), 0);
}

void		music_base(t_explo *explo)
{
  music_game(explo);
  if (sfMusic_getStatus(explo->music[SND_BASE]) == sfStopped)
    play_stop_music(explo, vector2i(1, SND_BASE),
		    vector2i(0, 0), 0);
}
