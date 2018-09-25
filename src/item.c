/*
** item.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Oct  4 23:58:17 2017 maxence.fourrier
** Last update Thu Oct 12 19:02:32 2017 maxence.fourrier
*/

#include "explo.h"

char		*my_strcpy(char *str)
{
  char		*ret;
  int		i;

  i = 0;
  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char		**init_item_other(char **ret)
{
  if ((ret[16] = my_strcpy("")) == NULL
      || (ret[17] = my_strcpy("")) == NULL
      || (ret[18] = my_strcpy("")) == NULL
      || (ret[19] = my_strcpy("")) == NULL
      || (ret[19 + MODULE_SOLAR] = my_strcpy("SOLAR PANEL")) == NULL
      || (ret[19 + MODULE_COAL] = my_strcpy("COAL FACTORY")) == NULL
      || (ret[19 + MODULE_LAUNCHER] = my_strcpy("LAUNCHER")) == NULL
      || (ret[19 + MODULE_NUCLEAR] = my_strcpy("NUCLEAR REACTOR")) == NULL
      || (ret[19 + MODULE_FUSION] = my_strcpy("FUSION REACTOR")) == NULL
      || (ret[19 + MODULE_CHEST] = my_strcpy("CHEST")) == NULL
      || (ret[19 + MODULE_DRILL] = my_strcpy("DRILL ENGINE")) == NULL
      || (ret[19 + MODULE_LASER] = my_strcpy("LASER TOWER")) == NULL)
    return (NULL);
  return (ret);
}

char		**init_item_name()
{
  char		**ret;

  if ((ret = malloc(sizeof(char *) * (NB_ITEM + 1))) == NULL
      || (ret[0] = my_strcpy("ROCK")) == NULL
      || (ret[COAL - '0' + 1] = my_strcpy("COAL")) == NULL
      || (ret[IRON - '0' + 1] = my_strcpy("IRON")) == NULL
      || (ret[COPPER - '0' + 1] = my_strcpy("COPPER")) == NULL
      || (ret[LITHIUM - '0' + 1] = my_strcpy("LITHIUM")) == NULL
      || (ret[URANIUM - '0' + 1] = my_strcpy("URANIUM")) == NULL
      || (ret[TITANIUM - '0' + 1] = my_strcpy("TITANIUM")) == NULL
      || (ret[IRIDIUM - '0' + 1] = my_strcpy("IRIDIUM")) == NULL
      || (ret[CARBON - '0' + 1] = my_strcpy("CARBON")) == NULL
      || (ret[GLASS - '0' + 1] = my_strcpy("GLASS")) == NULL
      || (ret[SAND - '0' + 1] = my_strcpy("SAND")) == NULL
      || (ret[ANTI - '0' + 1] = my_strcpy("ANTIMATTER")) == NULL
      || (ret[FOOD - '0' + 1] = my_strcpy("HEALTH")) == NULL
      || (ret[13] = my_strcpy("")) == NULL
      || (ret[14] = my_strcpy("")) == NULL
      || (ret[15] = my_strcpy("")) == NULL
      || (ret = init_item_other(ret)) == NULL)
    return (ret);
  return (ret);
}
