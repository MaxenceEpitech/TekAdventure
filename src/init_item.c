/*
** init_item.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 21 15:06:50 2017 maxence.fourrier
** Last update Sun Oct  8 23:12:46 2017 jean-baptiste
*/

#include "explo.h"

sfSprite	**init_module_item()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (sprite[SPR_0] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[MODULE_SOLAR] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[2] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[3] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[4] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[5] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[6] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[7] = load_picture(PATH_SPRITE_0)) == NULL)
    return (NULL);
  sprite[8] = NULL;
  return (sprite);
}

sfSprite	**init_other_item(sfSprite **sprite)
{
  if ((sprite[19] = load_picture(PATH_ANTI)) == NULL
      || (sprite[SPR_I_SOLAR] = load_picture(PATH_I_SOLAR)) == NULL
      || (sprite[SPR_I_COAL] = load_picture(PATH_I_COAL)) == NULL
      || (sprite[SPR_I_LAUNCHER] = load_picture(PATH_I_LAUNCHER)) == NULL
      || (sprite[SPR_I_NUCLEAR] = load_picture(PATH_I_NUCLEAR)) == NULL
      || (sprite[SPR_I_FUSION] = load_picture(PATH_I_FUSION)) == NULL
      || (sprite[SPR_I_CHEST] = load_picture(PATH_I_CHEST)) == NULL
      || (sprite[SPR_I_DRILL] = load_picture(PATH_I_DRILL)) == NULL
      || (sprite[SPR_I_CARBON] = load_picture(PATH_I_CARBON)) == NULL
      || (sprite[SPR_I_GLASS] = load_picture(PATH_I_GLASS)) == NULL
      || (sprite[SPR_I_LASER] = load_picture(PATH_I_LASER)) == NULL)
    return (NULL);
  sprite[30] = NULL;
  return (sprite);
}

sfSprite	**init_item()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (sprite[SPR_ROCK] = load_picture(PATH_ROCK)) == NULL
      || (sprite[SPR_COAL] = load_picture(PATH_COAL)) == NULL
      || (sprite[SPR_IRON] = load_picture(PATH_IRON)) == NULL
      || (sprite[SPR_COPPER] = load_picture(PATH_COPPER)) == NULL
      || (sprite[SPR_LITHIUM] = load_picture(PATH_LITHIUM)) == NULL
      || (sprite[SPR_URANIUM] = load_picture(PATH_URANIUM)) == NULL
      || (sprite[SPR_TITANIUM] = load_picture(PATH_TITANIUM)) == NULL
      || (sprite[SPR_IRIDIUM] = load_picture(PATH_IRIDIUM)) == NULL
      || (sprite[SPR_CARBON] = load_picture(PATH_CARBON)) == NULL
      || (sprite[SPR_GLASS] = load_picture(PATH_GLASS)) == NULL
      || (sprite[SPR_SAND] = load_picture(PATH_SAND)) == NULL
      || (sprite[SPR_ANTI] = load_picture(PATH_ANTI)) == NULL
      || (sprite[SPR_FOOD] = load_picture(PATH_FOOD)) == NULL
      || (sprite[13] = load_picture(PATH_ANTI)) == NULL
      || (sprite[14] = load_picture(PATH_ANTI)) == NULL
      || (sprite[15] = load_picture(PATH_ANTI)) == NULL
      || (sprite[16] = load_picture(PATH_ANTI)) == NULL
      || (sprite[17] = load_picture(PATH_ANTI)) == NULL
      || (sprite[18] = load_picture(PATH_ANTI)) == NULL
      || (sprite = init_other_item(sprite)) == NULL)
    return (NULL);
  return (sprite);
}
