/*
** init_craft_module_other_.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 16:04:28 2017 maxence.fourrier
** Last update Tue Oct 10 16:43:21 2017 maxence.fourrier
*/

#include "explo.h"

t_module	*init_laser(t_module *module)
{
  if ((module->quantity = malloc(sizeof(int*) * 11)) == NULL)
    return (NULL);
  module->type = PLACEABLE;
  module->quantity[0] = 0;
  module->quantity[COAL - '0' + 1] = 0;
  module->quantity[IRON - '0' + 1] = 5;
  module->quantity[COPPER - '0' + 1] = 0;
  module->quantity[LITHIUM - '0' + 1] = 10;
  module->quantity[URANIUM - '0' + 1] = 2;
  module->quantity[TITANIUM - '0' + 1] = 10;
  module->quantity[IRIDIUM - '0' + 1] = 0;
  module->quantity[CARBON - '0' + 1] = 10;
  module->quantity[GLASS - '0' + 1] = 0;
  module->quantity[10] = -1;
  return (module);
}
