/*
** init_game.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 10:47:13 2017 maxence.fourrier
** Last update Wed Oct 11 15:08:15 2017 maxence.fourrier
*/

#include "explo.h"

t_game		*init_game_other(t_game *game, t_config *config)
{
  if ((game->move_pos = init_move_pos()) == NULL
      || (game->storm = init_storm()) == NULL
      || (game->item_name = init_item_name()) == NULL
      || (game->mob = init_mob()) == NULL
      || (game->rock_limit = init_rock_limit()) == NULL
      || (game->depth = init_depth(config)) == NULL
      || (game->front_mob = init_mob_front(GIF_14_NAME)) == NULL
      || (game->back_mob = init_mob_back(GIF_14_NAME)) == NULL)
    return (NULL);
  game->size = vector2i(config->map_size_x, config->map_size_y);
  game->draw_time = get_time();
  game->regen_player = get_time();
  game->regen_base = get_time();
  game->conso_oxy = get_time();
  game->spawn_mob = get_time();
  game->music = 0;
  game->base = vector2i(((config->map_size_x / 2)
			 * SPRITE_FLOOR_SIZE) - (BASE_X / 2),
			((config->map_size_y / 2)
			 * SPRITE_FLOOR_SIZE) - (BASE_Y / 2));
  return (game);
}

t_game		*init_game(t_config *config)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL
      || (game->map = init_map(config)) == NULL
      || (game->ore = init_ore(config)) == NULL
      || (game->module = init_module(config)) == NULL
      || (game->placed = init_placed(config)) == NULL
      || (game->limit = init_limit(config)) == NULL
      || (game->upgrade = init_upgrade()) == NULL
      || (game->mountain = init_list_mountain(config->map_mountain,
					      vector2i(config->map_size_x,
						       config->map_size_y),
					      config)) == NULL
      || (game->fire = init_list_fire(config->map_fire,
				      vector2i(config->map_size_x,
					       config->map_size_y),
				      game, config)) == NULL
      || (game->rock = init_list_rock(config->map_rock,
				      vector2i(config->map_size_x,
					       config->map_size_y),
				      game, config)) == NULL
      || (game = init_game_other(game, config)) == NULL)
    return (NULL);
  return (game);
}

t_module	**init_module(t_config *config)
{
  t_module	**module;
  int		i;

  if ((module = malloc(sizeof(t_module*) * NB_MODULE)) == NULL)
    return (NULL);
  i = 0;
  while (i < NB_MODULE)
    {
      if ((module[i] = malloc(sizeof(t_module))) == NULL)
	return (NULL);
      i++;
    }
  module[MODULE_BASE]->type = MODULE_BASE;
  init_craft_module(module);
  return (module);
}
