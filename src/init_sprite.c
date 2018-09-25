/*
** init_sprite.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Sep 13 12:46:32 2017 maxence.fourrier
** Last update Sun Oct  8 21:39:54 2017 maxence.fourrier
*/

#include "explo.h"

void		init_pos_sprite(t_explo *explo)
{
  sfVector2f	vec;

  vec = vector2f(((explo->game->size.x / 2)
		  * SPRITE_FLOOR_SIZE) - (BASE_X / 2),
		 ((explo->game->size.y / 2)
		  * SPRITE_FLOOR_SIZE) - (BASE_Y / 2));
  sfSprite_setPosition(explo->sprite[SPR_HOME], vec);
}

sfSprite	**init_sprite()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (sprite[SPR_0] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[SPR_INV] = load_picture(PATH_INV)) == NULL
      || (sprite[SPR_ROCK_] = load_picture(PATH_INV)) == NULL
      || (sprite[SPR_FIRE] = load_picture(PATH_INV)) == NULL
      || (sprite[SPR_MOUNTAIN] = load_picture(PATH_INV)) == NULL
      || (sprite[SPR_INV_EQU] = load_picture(PATH_INV_EQU)) == NULL
      || (sprite[SPR_FLOOR_1] = load_picture(PATH_FLOOR_1)) == NULL
      || (sprite[SPR_FLOOR_2] = load_picture(PATH_FLOOR_2)) == NULL
      || (sprite[SPR_FLOOR_3] = load_picture(PATH_FLOOR_3)) == NULL
      || (sprite[SPR_FLOOR_4] = load_picture(PATH_FLOOR_4)) == NULL
      || (sprite[SPR_FLOOR_5] = load_picture(PATH_FLOOR_5)) == NULL
      || (sprite[SPR_CHARAC] = load_picture(PATH_CHARAC)) == NULL
      || (sprite[SPR_CLICK] = load_picture(PATH_CLICK)) == NULL
      || (sprite[SPR_HOME] = load_picture(PATH_HOME)) == NULL
      || (sprite[SPR_SOLAR] = load_picture(PATH_SOLAR)) == NULL
      || (sprite[SPR_ARROW_R] = load_picture(PATH_ARROW_R)) == NULL
      || (sprite[SPR_ARROW_G] = load_picture(PATH_ARROW_G)) == NULL
      || (sprite = init_other_sprite(sprite)) == NULL)
    return (NULL);
  return (sprite);
}

sfSprite	**init_placed_sprite()
{
  sfSprite	**placed;

  if ((placed = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (placed[SPR_P_BASE]
	  = load_picture(PATH_P_BASE)) == NULL
      || (placed[SPR_P_SOLAR]
	  = load_picture(PATH_P_SOLAR)) == NULL
      || (placed[SPR_P_COAL]
	  = load_picture(PATH_P_COAL)) == NULL
      || (placed[SPR_P_LAUNCHER]
	  = load_picture(PATH_P_LAUNCHER)) == NULL
      || (placed[SPR_P_NUCLEAR]
	  = load_picture(PATH_P_NUCLEAR)) == NULL
      || (placed[SPR_P_FUSION]
	  = load_picture(PATH_P_FUSION)) == NULL
      || (placed[SPR_P_CHEST]
	  = load_picture(PATH_P_CHEST)) == NULL
      || (placed[SPR_P_LASER]
	  = load_picture(PATH_P_LASER)) == NULL)
    return (NULL);
  return (placed);
}
