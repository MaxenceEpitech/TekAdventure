/*
** init_craft_module.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 19 18:52:10 2017 maxence.fourrier
** Last update Tue Oct 10 16:16:41 2017 maxence.fourrier
*/

#include "explo.h"

t_module	*init_solar(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 0;
  module->quantity[COPPER - '0' + 1] = 10;
  module->quantity[LITHIUM - '0' + 1] = 5;
  module->quantity[URANIUM - '0' + 1] = 2;
  module->quantity[TITANIUM - '0' + 1] = 10;
  module->quantity[IRIDIUM - '0' + 1] = 1;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 6;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_coal(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 15;
  module->quantity[COPPER - '0' + 1] = 10;
  module->quantity[LITHIUM - '0' + 1] = 0;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 0;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_launcher(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 10;
  module->quantity[COPPER - '0' + 1] = 20;
  module->quantity[LITHIUM - '0' + 1] = 10;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 20;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 10;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_central(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 7;
  module->quantity[COPPER - '0' + 1] = 10;
  module->quantity[LITHIUM - '0' + 1] = 8;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 10;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 4;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

void		init_craft_module(t_module **module)
{
  module[MODULE_SOLAR] = init_solar(module[MODULE_SOLAR]);
  module[MODULE_COAL] = init_coal(module[MODULE_COAL]);
  module[MODULE_LAUNCHER] = init_launcher(module[MODULE_LAUNCHER]);
  module[MODULE_NUCLEAR] = init_central(module[MODULE_NUCLEAR]);
  module[MODULE_FUSION] = init_fusion(module[MODULE_FUSION]);
  module[MODULE_CHEST] = init_chest(module[MODULE_CHEST]);
  module[ITEM_DRILL] = init_drill(module[ITEM_DRILL]);
  module[ITEM_CARBON] = init_carbon(module[ITEM_CARBON]);
  module[ITEM_GLASS] = init_glass(module[ITEM_GLASS]);
  module[MODULE_LASER] = init_laser(module[MODULE_LASER]);
  module[11] = NULL;
}
