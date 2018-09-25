/*
** init_sprite_other.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 21:38:52 2017 maxence.fourrier
** Last update Fri Oct 13 10:38:02 2017 maxence.fourrier
*/

#include "explo.h"

sfSprite	**init_other_other_other_sprite(sfSprite **sprite)
{
  if ((sprite[SPR_SKY] = load_picture(PATH_SKY)) == NULL
      || (sprite[SPR_MENU] = load_picture(PATH_MENU)) == NULL
      || (sprite[SPR_MENU_HELP] = load_picture(PATH_MENU_HELP)) == NULL
      || (sprite[SPR_MENU_NEW] = load_picture(PATH_MENU_NEW)) == NULL
      || (sprite[SPR_MENU_LOAD] = load_picture(PATH_MENU_LOAD)) == NULL
      || (sprite[SPR_MENU_OPT] = load_picture(PATH_MENU_OPT)) == NULL
      || (sprite[SPR_MENU_Q] = load_picture(PATH_MENU_Q)) == NULL
      || (sprite[SPR_OPT] = load_picture(PATH_OPT)) == NULL
      || (sprite[SPR_HELP] = load_picture(PATH_HELP)) == NULL
      || (sprite[SPR_SOON] = load_picture(PATH_SOON)) == NULL
      || (sprite[SPR_SPLASH] = load_picture(PATH_SPLASH)) == NULL
      || (sprite[SPR_LOST] = load_picture(PATH_LOST)) == NULL)
    return (NULL);
  sprite[67] = NULL;
  return (sprite);
}

sfSprite	**init_other_other_sprite(sfSprite **sprite)
{
  if ((sprite[SPR_ADD_R] = load_picture(PATH_ADD_R)) == NULL
      || (sprite[SPR_NUCLEAR_REAC] = load_picture(PATH_NUCLEAR_REAC)) == NULL
      || (sprite[SPR_LAUNCHER_B] = load_picture(PATH_LAUNCHER_B)) == NULL
      || (sprite[SPR_FUSION_B] = load_picture(PATH_FUSION_B)) == NULL
      || (sprite[SPR_TAKE] = load_picture(PATH_TAKE)) == NULL
      || (sprite[SPR_TAKE_] = load_picture(PATH_TAKE_)) == NULL
      || (sprite[SPR_TRASH] = load_picture(PATH_TRASH)) == NULL
      || (sprite[SPR_MINE_1] = load_picture(PATH_MINE_1)) == NULL
      || (sprite[SPR_MINE_2] = load_picture(PATH_MINE_2)) == NULL
      || (sprite[SPR_MINE_3] = load_picture(PATH_MINE_3)) == NULL
      || (sprite[SPR_ROCK_0] = load_picture(PATH_ROCK_0)) == NULL
      || (sprite[SPR_ROCK_1] = load_picture(PATH_ROCK_1)) == NULL
      || (sprite[SPR_ROCK_2] = load_picture(PATH_ROCK_2)) == NULL
      || (sprite[SPR_ROCK_3] = load_picture(PATH_ROCK_3)) == NULL
      || (sprite[SPR_LAKE] = load_picture(PATH_LAKE)) == NULL
      || (sprite[SPR_LASER_T] = load_picture(PATH_LASER_T)) == NULL
      || (sprite = init_other_other_other_sprite(sprite)) == NULL)
    return (NULL);
  return (sprite);
}

sfSprite	**init_other_sprite(sfSprite **sprite)
{
  if ((sprite[SPR_CRAFT] = load_picture(PATH_CRAFT)) == NULL
      || (sprite[SPR_INV_G] = load_picture(PATH_INV_G)) == NULL
      || (sprite[SPR_INV_R] = load_picture(PATH_INV_R)) == NULL
      || (sprite[SPR_INV_SOLAR] = load_picture(PATH_INV_SOLAR)) == NULL
      || (sprite[SPR_LINK] = load_picture(PATH_LINK)) == NULL
      || (sprite[SPR_LINK_] = load_picture(PATH_LINK_)) == NULL
      || (sprite[SPR_DONE] = load_picture(PATH_DONE)) == NULL
      || (sprite[SPR_UPGRADE] = load_picture(PATH_UPGRADE)) == NULL
      || (sprite[SPR_UPGRADE_] = load_picture(PATH_UPGRADE_)) == NULL
      || (sprite[SPR_ON] = load_picture(PATH_ON)) == NULL
      || (sprite[SPR_ON_] = load_picture(PATH_ON_)) == NULL
      || (sprite[SPR_OFF] = load_picture(PATH_OFF)) == NULL
      || (sprite[SPR_OFF_] = load_picture(PATH_OFF_)) == NULL
      || (sprite[SPR_BLACK] = load_picture(PATH_BLACK)) == NULL
      || (sprite[SPR_SPEED] = load_picture(PATH_SPEED)) == NULL
      || (sprite[SPR_AMOUNT] = load_picture(PATH_AMOUNT)) == NULL
      || (sprite[SPR_BATTERY] = load_picture(PATH_BATTERY)) == NULL
      || (sprite[SPR_LEVEL] = load_picture(PATH_LEVEL)) == NULL
      || (sprite[SPR_INV_CHEST] = load_picture(PATH_INV_CHEST)) == NULL
      || (sprite[SPR_FURNACE] = load_picture(PATH_FURNACE)) == NULL
      || (sprite[SPR_ADD_G] = load_picture(PATH_ADD_G)) == NULL
      || (sprite[SPR_ADD_G_] = load_picture(PATH_ADD_G_)) == NULL
      || (sprite = init_other_other_sprite(sprite)) == NULL)
    return (NULL);
  return (sprite);
}
