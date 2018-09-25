/*
** init_explo.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Sep  4 09:49:45 2017 maxence.fourrier
** Last update Sun Oct  8 21:55:08 2017 maxence.fourrier
*/

#include <time.h>
#include "explo.h"

t_explo		*init_explo(char *file)
{
  t_explo	*explo;

  srand(time(NULL));
  if ((explo = malloc(sizeof(t_explo))) == NULL
      || (explo->config = init_config(file)) == NULL
      || (check_config(file, explo->config)) == ERROR
      || (explo->player = init_player(explo->config)) == NULL
      || (explo->game = init_game(explo->config)) == NULL
      || (explo->graph = init_graph(explo->player)) == NULL
      || (explo->sprite = init_sprite()) == NULL
      || (explo->module = init_module_item()) == NULL
      || (explo->item = init_item()) == NULL
      || (explo->hud = init_hud()) == NULL
      || (explo->floor = init_floor()) == NULL
      || (explo->circle = init_circle(explo)) == NULL
      || (explo->placed = init_placed_sprite()) == NULL
      || (explo->day = init_day()) == NULL
      || (explo->gif = init_gif()) == NULL
      || (explo->music = init_music()) == NULL)
    return (NULL);
  init_pos_sprite(explo);
  draw_hud_bar(explo);
  return (explo);
}

sfView		*init_view(t_player *player)
{
  sfView	*view;
  sfFloatRect	rect;

  rect.left = 0;
  rect.top = 0;
  rect.width = 1;
  rect.height = 0.5;
  view = sfView_create();
  sfView_setCenter(view, player->pos);
  sfView_setSize(view, vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
  return (view);
}

sfText		*init_text(sfFont *font)
{
  sfText	*text;

  if ((text = sfText_create()) == NULL)
    return (NULL);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 50);
  return (text);
}

t_graph		*init_graph(t_player *player)
{
  t_graph	*graph;

  if ((graph = malloc(sizeof(t_graph))) == NULL
      || (graph->window =
          create_window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->font = sfFont_createFromFile(FONT)) == NULL
      || (graph->text = init_text(graph->font)) == NULL
      || (graph->sprite = sfSprite_create()) == NULL
      || (graph->time = sfSprite_create()) == NULL
      || (!graph->window)
      || (graph->texture
	  = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->tex_time
	  = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->view = init_view(player)) == NULL
      || (graph->framebuffer =
	  my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->framebuffer_time =
	  my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
  sfSprite_setTexture(graph->time, graph->tex_time, sfTrue);
  sfRenderWindow_setView(graph->window, graph->view);
  return (graph);
}
