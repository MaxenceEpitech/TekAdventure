/*
** chest.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Sep 28 11:27:56 2017 maxence.fourrier
** Last update Sun Oct  8 19:43:27 2017 maxence.fourrier
*/

#include "explo.h"

t_inv		*get_inv_clicked(t_explo *explo, t_placed_mod *placed,
				 sfVector2i *pos, int nb)
{
  sfVector2i	pos1;

  pos1 = check_clicked_pos(explo);
  if (pos1.x != -1 &&
      (placed->inv[pos1.y][pos1.x]->item != -1 || nb == 2))
    {
      *pos = pos1;
      return (placed->inv[pos1.y][pos1.x]);
    }
  pos1 = check_clicked_pos_equ(explo);
  if (pos1.x != -1 &&
      (explo->player->inv[pos1.y][pos1.x]->item != -1 || nb == 2))
    {
      *pos = pos1;
      return (explo->player->inv[pos1.y][pos1.x]);
    }
  return (NULL);
}

int		change_item_chest(t_explo *explo, sfVector2i pos1,
				  t_inv *inv1, t_placed_mod *placed)
{
  sfVector2i	pos2;
  t_inv		*inv2;
  sfVector2i	item;

  if (click_trash(explo))
    {
      inv1->item = -1;
      inv1->quantity = -1;
      return (1);
    }
  if ((inv2 = get_inv_clicked(explo, placed, &pos2, 2)) == NULL)
    return (SUCCESS);
  item = vector2i(inv1->item, inv1->quantity);
  inv1->item = inv2->item;
  inv1->quantity = inv2->quantity;
  inv2->item = item.x;
  inv2->quantity = item.y;
  return (1);
}

int		click_chest(t_explo *explo, t_placed_mod *placed,
			    int *draw)
{
  sfVector2i	pos1;
  t_inv		*inv;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      if ((inv = get_inv_clicked(explo, placed, &pos1, 1)) == NULL)
	return (SUCCESS);
      wait_mouse(explo->graph->window);
      while (!sfKeyboard_isKeyPressed(sfKeyEscape)
	     && !sfKeyboard_isKeyPressed(sfKeyE))
	{
	  draw_chest(explo, placed, pos1, draw);
	  draw_chest_cursor(explo, inv);
	  if (sfMouse_isButtonPressed(sfMouseLeft)
	      && change_item_chest(explo, pos1, inv, placed))
	    return (1);
	}
    }
  return (SUCCESS);
}

int		chest(t_explo *explo, t_placed_mod *placed)
{
  int		draw;

  draw = 0;
  draw_chest(explo, placed, vector2i(-1, -1), &draw);
  sfRenderWindow_display(explo->graph->window);
  while (1)
    {
      explo->game->time = get_time();
      if (get_event() == ESCAPE
          && !wait_key(explo->graph->window, sfKeyEscape))
	break;
      if (click_chest(explo, placed, &draw))
	wait_mouse(explo->graph->window);
      draw_chest(explo, placed, vector2i(-1, -1), &draw);
      sfRenderWindow_display(explo->graph->window);
    }
  return (SUCCESS);
}
