/*
** init_craft_module_other.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 19 19:09:44 2017 maxence.fourrier
** Last update Tue Oct 10 16:14:34 2017 maxence.fourrier
*/

#include "explo.h"

t_module	*init_fusion(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 20;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 30;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 40;
  module->quantity[IRIDIUM - '0' + 1] = 3;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 5;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_chest(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 5;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 0;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 0;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_drill(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = 1;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 5;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 1;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 0;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_carbon(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = 1;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 4;
  module->quantity[IRON - '0' + 1] = 2;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 0;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 0;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}

t_module	*init_glass(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = 1;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 1;
  module->quantity[IRON - '0' + 1] = 0;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 0;
  module->quantity[URANIUM - '0' + 1] = 0;
  module->quantity[TITANIUM - '0' + 1] = 0;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 0;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[SAND - '0' + 1] = 10;
  module->quantity[11] = -1;
  return (module);
}
