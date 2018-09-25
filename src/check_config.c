/*
** check_config.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 10:52:32 2017 maxence.fourrier
** Last update Sun Oct  8 23:30:25 2017 maxence.fourrier
*/

#include "explo.h"

int		check_config_other(char *file, t_config *config)
{
  int		ret;

  ret = SUCCESS;
  if (config->player_speed < 0 || config->player_speed > 5)
    ret = msg_error(file, new_cat(M_P_SPEED, M_P_SPEED_2));
  if (config->planets < 2 || config->planets > 20)
    ret = msg_error(file, new_cat(M_PLANETS, M_PLANETS_2));
  if (!(config->console == 1 || config->console == 0))
    ret = msg_error(file, M_CONSOLE);
  if (!(config->storm == 1 || config->storm == 0))
    ret = msg_error(file, M_STORM);
  return (ret);
}

int		check_config(char *file, t_config *config)
{
  int		ret;

  ret = SUCCESS;
  if (config->difficulty > 3 || config->difficulty < 1)
    ret = msg_error(file, M_DIFFICULTY);
  if (config->map_size_x < 100 || config->map_size_y < 100)
    ret = msg_error(file, new_cat(M_M_SIZE, M_M_SIZE_2));
  if (config->map_mountain > 80 || config->map_mountain < 1)
    ret = msg_error(file, new_cat(M_M_MOUNTAIN, M_M_MOUNTAIN_2));
  if (config->map_fire > 40 || config->map_fire < 1)
    ret = msg_error(file, new_cat(M_M_FIRE, M_M_FIRE_2));
  if (config->map_rock > 1200 || config->map_rock < 1)
    ret = msg_error(file, new_cat(M_M_ROCK, M_M_ROCK_2));
  if (config->player_oxy > 100 || config->player_oxy < 0)
    ret = msg_error(file, new_cat(M_P_OXY, M_P_OXY_2));
  if (config->player_hp > 100 || config->player_hp < 0)
    ret = msg_error(file, new_cat(M_P_HP, M_P_HP_2));
  if (config->player_power > 100 || config->player_power < 0)
    ret = msg_error(file, new_cat(M_P_POWER, M_P_POWER_2));
  if (ret != SUCCESS)
    return (ret);
  ret = check_config_other(file, config);
  return (ret);
}
