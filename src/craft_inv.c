/*
** craft_inv.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Sep 19 09:51:23 2017 maxence.fourrier
** Last update Wed Oct 11 18:56:26 2017 maxence.fourrier
*/

#include "explo.h"

int		check_clicked_craft(t_explo *explo)
{
  int		i;
  sfVector2i	vec;

  vec = sfMouse_getPositionRenderWindow(explo->graph->window);
  i = 0;
  while (i < SIZE_OF_PAGE)
    {
      if (vec.x >= 50
	  && vec.x < 50 + ITEM_SIZE_X
	  && vec.y >= 19 + (i * (ITEM_SIZE_Y + 20))
	  && vec.y < 19 + ((ITEM_SIZE_Y + 20) * i) + 114)
	return (i);
      i++;
    }
  return (ERROR);
}

int		del_from_inv(t_explo *explo, int item)
{
  int		x;
  sfVector2i	vec;

  x = 0;
  while (explo->game->module[item]->quantity[x] != -1)
    {
      if (explo->game->module[item]->quantity[x] > 0)
	use_inv_item(explo->player->inv, x,
		     explo->game->module[item]->quantity[x]);
      x++;
    }
  if (item + 19 <= 26 || item == 10)
    add_item_inv_console(explo->player->inv, item + 19, 1);
  else
    add_item_inv_console(explo->player->inv, item, 1);
}

int		craft_item(t_explo *explo, int page)
{
  int		pos;
  int		x;

  if (sfMouse_isButtonPressed(sfMouseLeft)
      && (pos = check_clicked_craft(explo)) != ERROR)
    {
      if (is_craftable(explo, 1 + pos + (page * SIZE_OF_PAGE)))
	{
	  del_from_inv(explo, 1 + pos + (page * SIZE_OF_PAGE));
	  wait_mouse(explo->graph->window);
	  return (1);
	}
      wait_mouse(explo->graph->window);
    }
  return (SUCCESS);
}

int		change_page(t_explo *explo, int page)
{
  if (get_event() == LEFT
      && !wait_key(explo->graph->window, sfKeyLeft)
      && page - 1 >= 0)
    {
      page -= 1;
      draw_craft_inv(explo, page);
    }
  if (get_event() == RIGHT
      && !wait_key(explo->graph->window, sfKeyRight)
      && page + 1 < 2)
    {
      page += 1;
      draw_craft_inv(explo, page);
    }
  return (page);
}

void		craft_inventory(t_explo *explo)
{
  int		page;

  page = 0;
  draw_craft_inv(explo, page);
  wait_key(explo->graph->window, sfKeyI);
  while (1)
    {
      if ((get_event() == ESCAPE) &&
	  !wait_key(explo->graph->window, sfKeyEscape))
	break;
      if ((sfKeyboard_isKeyPressed(sfKeyI)) &&
	  !wait_key(explo->graph->window, sfKeyI))
        break;
      page = change_page(explo, page);
      if (craft_item(explo, page))
	draw_craft_inv(explo, page);
    }
}
