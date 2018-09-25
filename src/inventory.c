/*
** inventory.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep  7 15:23:26 2017 maxence.fourrier
** Last update Tue Oct 10 16:34:19 2017 maxence.fourrier
*/

#include "explo.h"

int		swap_item(t_explo *explo, sfVector2i pos1,
			  sfVector2i pos2)
{
  int		tmp;
  int		quantity;

  quantity = explo->player->inv[pos1.y][pos1.x]->quantity;
  tmp = explo->player->inv[pos1.y][pos1.x]->item;
  explo->player->inv[pos1.y][pos1.x]->quantity =
    explo->player->inv[pos2.y][pos2.x]->quantity;
  explo->player->inv[pos1.y][pos1.x]->item =
    explo->player->inv[pos2.y][pos2.x]->item;
  explo->player->inv[pos2.y][pos2.x]->quantity = quantity;
  explo->player->inv[pos2.y][pos2.x]->item = tmp;
  return (1);
}

int		change_item_pressed_draw(t_explo *explo, sfVector2i pos1,
					 sfVector2i pos2)
{
  if (pos1.x == pos2.x && pos1.y == pos2.y)
    return (1);
  if (explo->player->inv[pos1.y][pos1.x]->item
      != explo->player->inv[pos2.y][pos2.x]->item)
    return (swap_item(explo, pos1, pos2));
  if (explo->player->inv[pos1.y][pos1.x]->item
      == explo->player->inv[pos2.y][pos2.x]->item)
    return (add_item(explo, pos1, pos2));
}

int		change_item_pressed(t_explo *explo, sfVector2i pos1,
				    t_inv *inv, int *cpt)
{
  sfVector2i	pos2;

  pos2.x = -1;
  draw_cursor(inv, explo, pos1, cpt);
  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      pos2 = check_clicked_pos(explo);
      if (pos2.x == -1)
	pos2 = check_clicked_pos_equ(explo);
      if (pos2.x != -1)
	return (change_item_pressed_draw(explo, pos1, pos2));
      if (click_trash(explo))
	{
	  explo->player->inv[pos1.y][pos1.x]->item = -1;
	  explo->player->inv[pos1.y][pos1.x]->quantity = -1;
	  return (1);
	}
    }
  return (SUCCESS);
}

int		change_item(t_explo *explo, int *cpt)
{
  sfVector2i	pos1;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      pos1 = check_clicked_pos(explo);
      if (pos1.x == -1)
	pos1 = check_clicked_pos_equ(explo);
      if (pos1.x != -1 && explo->player->inv[pos1.y][pos1.x]
	  ->item == FOOD - '0' + 1 && explo->player->hp <= 100 - FOOD_HEAL)
	return (use_food(explo, pos1));
      if (pos1.x != -1 && explo->player->inv[pos1.y][pos1.x]->item != -1)
	{
	  wait_mouse(explo->graph->window);
	  while (!sfKeyboard_isKeyPressed(sfKeyEscape)
		 && !sfKeyboard_isKeyPressed(sfKeyE))
	    if (change_item_pressed(explo, pos1,
				    explo->player->inv[pos1.y]
				    [pos1.x], cpt))
	      return (1);
	}
    }
  return (SUCCESS);
}

int		inventory(t_explo *explo)
{
  int		cpt;

  cpt = 0;
  draw_inventory(explo, vector2i(-2, -2), &cpt);
  sfRenderWindow_display(explo->graph->window);
  wait_key(explo->graph->window, sfKeyE);
  while (1)
    {
      if (get_event() == ESCAPE
	  && !wait_key(explo->graph->window, sfKeyEscape))
	break;
      if (get_event() == INVENTORY
	  && !wait_key(explo->graph->window, sfKeyE))
	break;
      if (change_item(explo, &cpt))
	wait_mouse(explo->graph->window);
      draw_inventory(explo, vector2i(-2, -2), &cpt);
      sfRenderWindow_display(explo->graph->window);
    }
  return (SUCCESS);
}
