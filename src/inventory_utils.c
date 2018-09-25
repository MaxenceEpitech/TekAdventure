/*
** inventory_utils.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Sep 24 03:35:03 2017 maxence.fourrier
** Last update Sun Oct  8 23:04:29 2017 jean-baptiste
*/

#include "explo.h"

int		add_item_full_stack(t_explo *explo, sfVector2i pos1,
				    sfVector2i pos2)
{
  int		tmp;

  if (explo->player->inv[pos2.y][pos2.x]->quantity >= 9
      || explo->player->inv[pos1.y][pos1.x]->quantity >= 9)
    {
      tmp = explo->player->inv[pos1.y][pos1.x]->quantity;
      explo->player->inv[pos1.y][pos1.x]->quantity =
	explo->player->inv[pos2.y][pos2.x]->quantity;
      explo->player->inv[pos2.y][pos2.x]->quantity = tmp;
    }
  return (1);
}

int		add_item(t_explo *explo, sfVector2i pos1,
			 sfVector2i pos2)
{
  if (explo->player->inv[pos2.y][pos2.x]->quantity +
      explo->player->inv[pos1.y][pos1.x]->quantity <= STACK_SIZE)
    {
      explo->player->inv[pos2.y][pos2.x]->quantity
        += explo->player->inv[pos1.y][pos1.x]->quantity;
      explo->player->inv[pos1.y][pos1.x]->quantity = -1;
      explo->player->inv[pos1.y][pos1.x]->item = -1;
      return (1);
    }
  if (explo->player->inv[pos2.y][pos2.x]->quantity < 9
      && explo->player->inv[pos1.y][pos1.x]->quantity < 9)
    {
      explo->player->inv[pos1.y][pos1.x]->quantity =
        explo->player->inv[pos2.y][pos2.x]->quantity -
        (9 - explo->player->inv[pos1.y][pos1.x]->quantity);
      explo->player->inv[pos2.y][pos2.x]->quantity = 9;
      return (1);
    }
  return (add_item_full_stack(explo, pos1, pos2));
}

int		click_trash(t_explo *explo)
{
  sfVector2i	click;

  click = sfMouse_getPositionRenderWindow(explo->graph->window);
  if (click.x >= 181 && click.x < 331
      && click.y >= 495 && click.y < 635)
    return (1);
  return (SUCCESS);
}

void		draw_name_item(t_explo *explo, int item, sfVector2i pos)
{
  sfVector2f	vec;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2) + pos.x,
		 explo->player->pos.y - (SCREEN_HEIGHT / 2) + pos.y);
  sfText_setPosition(explo->graph->text, vec);
  sfText_setStyle(explo->graph->text, sfTextBold);
  sfText_setCharacterSize(explo->graph->text, 60);
  sfText_setString(explo->graph->text, explo->game->item_name[item]);
  sfRenderWindow_drawText(explo->graph->window,
                          explo->graph->text, NULL);
  sfText_setCharacterSize(explo->graph->text, 50);
}
