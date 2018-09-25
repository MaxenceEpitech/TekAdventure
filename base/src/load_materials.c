/*
** load_materials.c for tekadventure in /home/camille/semestre2/tekadventure
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Aug 16 11:35:19 2017 camille
** Last update Sun Oct  8 17:04:14 2017 camille
*/

#include <stdlib.h>
#include "tek.h"

sfSprite	**load_spr(sfSprite **spr, sfTexture **tex)
{
  int		i;

  i = 0;
  if ((spr = malloc(sizeof(sfSprite *) * 12)) == NULL)
    return (NULL);
  while (i < 11)
    {
      spr[i] = sfSprite_create();
      sfSprite_setTexture(spr[i], tex[i], sfFalse);
      i += 1;
    }
  spr[11] = NULL;
  return (spr);
}

sfTexture	**load_tex(sfTexture **tex)
{
  if ((tex = malloc(sizeof(sfTexture *) * 12)) == NULL)
    return (NULL);
  tex[0] = sfTexture_create(WIDTH, HEIGHT);
  tex[1] = sfTexture_createFromFile(SKY, NULL);
  tex[2] = sfTexture_createFromFile(MENU, NULL);
  tex[3] = sfTexture_createFromFile(MENU_HELP, NULL);
  tex[4] = sfTexture_createFromFile(MENU_NEW, NULL);
  tex[5] = sfTexture_createFromFile(MENU_LOAD, NULL);
  tex[6] = sfTexture_createFromFile(MENU_OPT, NULL);
  tex[7] = sfTexture_createFromFile(MENU_Q, NULL);
  tex[8] = sfTexture_createFromFile(HELP, NULL);
  tex[9] = sfTexture_createFromFile(OPTIONS, NULL);
  tex[10] = sfTexture_createFromFile(SOON, NULL);
  tex[11] = NULL;
  return (tex);
}

sfMusic		**load_music(sfMusic **music)
{
  if ((music = malloc(sizeof(sfMusic *) * 5)) == NULL)
    return (NULL);
  music[0] = sfMusic_createFromFile(MUSIC_BATTLE1);
  music[1] = sfMusic_createFromFile(MUSIC_ASTER);
  music[2] = sfMusic_createFromFile(MUSIC_CANTINA);
  music[3] = sfMusic_createFromFile(MUSIC_EPIC);
  music[4] = '\0';
  return (music);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

t_materials	*prepare_game(t_materials *mats)
{
  if ((mats->tex = load_tex(mats->tex)) == NULL)
    return (NULL);
  if ((mats->spr = load_spr(mats->spr, mats->tex)) == NULL)
    return (NULL);
  if ((mats->music = load_music(mats->music)) == NULL)
    return (NULL);
  if ((mats->fb = create_fbuffer(WIDTH, HEIGHT)) == NULL)
    return (NULL);
  if ((mats->wdw = create_window(WIN_TITLE, WIDTH, HEIGHT)) == NULL)
    return (NULL);
  return (mats);
}
