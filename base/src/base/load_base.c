/*
** load_base.c for Project-Master in /home/camille/semestre2/tekadventure/base
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Oct  4 09:50:51 2017 camille
** Last update Sun Oct  8 17:08:56 2017 camille
*/

#include <stdlib.h>
#include "base.h"

sfSprite	**load_spr_base(sfSprite **spr, sfTexture **tex)
{
  int		i;

  i = 0;
  if ((spr = malloc(sizeof(sfSprite *) * 26)) == NULL)
    return (NULL);
  while (i < 26)
    {
      spr[i] = sfSprite_create();
      sfSprite_setTexture(spr[i], tex[i], sfFalse);
      i += 1;
    }
  return (spr);
}

sfTexture	**load_tex_base(sfTexture **tex)
{
  if ((tex = malloc(sizeof(sfTexture *) * 26)) == NULL)
    return (NULL);
  tex[0] = sfTexture_createFromFile(BASE_DAY, NULL);
  tex[1] = sfTexture_createFromFile(BASE_NIGHT, NULL);
  tex[2] = sfTexture_createFromFile(DASHBOARD, NULL);
  tex[3] = sfTexture_createFromFile(DASH_STAY, NULL);
  tex[4] = sfTexture_createFromFile(DASH_TRAVEL, NULL);
  tex[5] = sfTexture_createFromFile(DEC, NULL);
  tex[6] = sfTexture_createFromFile(DEC_COMPLETE, NULL);
  tex[7] = sfTexture_createFromFile(DEC_IMP, NULL);
  tex[8] = sfTexture_createFromFile(RESTED, NULL);
  tex[9] = sfTexture_createFromFile(RESTING, NULL);
  tex[10] = sfTexture_createFromFile(SCAN, NULL);
  tex[11] = sfTexture_createFromFile(SCAN_OK, NULL);
  tex = load_rest_textures(tex);
  return (tex);
}

sfTexture	**load_rest_textures(sfTexture **tex)
{
  tex[12] = sfTexture_createFromFile(SCAN_ERR1, NULL);
  tex[13] = sfTexture_createFromFile(SCAN_ERR2, NULL);
  tex[14] = sfTexture_createFromFile(TEST, NULL);
  tex[15] = sfTexture_createFromFile(TEST_NO, NULL);
  tex[16] = sfTexture_createFromFile(TEST_YES, NULL);
  tex[17] = sfTexture_createFromFile(RADIOAC, NULL);
  tex[18] = sfTexture_createFromFile(DEC_YES, NULL);
  tex[19] = sfTexture_createFromFile(DEC_NO, NULL);
  tex[20] = sfTexture_createFromFile(DEC_P1, NULL);
  tex[21] = sfTexture_createFromFile(DEC_P2, NULL);
  tex[22] = sfTexture_createFromFile(FADE_BLACK, NULL);
  tex[23] = sfTexture_createFromFile(BASE_LEFT, NULL);
  tex[24] = sfTexture_createFromFile(BASE_RIGHT, NULL);
  tex[25] = NULL;
  return (tex);
}

void		load_base(t_materials *mats)
{
  t_base	*base;

  if ((base = malloc(sizeof(t_base) * 1)) == NULL)
    return ;
  base->tex = NULL;
  base->spr = NULL;
  base->player.x = 502;
  base->player.y = 250;
  if ((base = init_sprites_base(base)) == NULL)
    return ;
  if ((base = init_coords_base(base)) == NULL)
    return ;
  if ((base->pos = malloc(sizeof(int))) == NULL)
    return ;
  base->side = 'r';
  base->bg.x = 0;
  base->bg.y = 0;
  base->warning = 0;
  start_base(mats, base);
  *base->pos = 0;
}
