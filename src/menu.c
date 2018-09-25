/*
** menu.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun Oct  8 21:20:43 2017 maxence.fourrier
** Last update Sun Oct  8 23:09:27 2017 jean-baptiste
*/

#include "explo.h"

void		draw_menu(t_explo *explo, sfVector2i click,
			  sfVector2f vec)
{
  int		sprite;

  sprite = SPR_MENU;
  if ((click.x >= 264 && click.x <= 460)
      && (click.y >= 446 && click.y <= 609))
    sprite = SPR_MENU_HELP;
  else if ((click.x >= 1003 && click.x <= 1282)
	   && (click.y >= 175 && click.y <= 367))
    sprite = SPR_MENU_NEW;
  else if ((click.x >= 723 && click.x <= 957)
	   && (click.y >= 456 && click.y <= 638))
    sprite = SPR_MENU_LOAD;
  else if ((click.x >= 85 && click.x <= 273)
	   && (click.y >= 232 && click.y <= 382))
    sprite = SPR_MENU_OPT;
  else if ((click.x >= 1023 && click.x <= 1147)
	   && (click.y >= 543 && click.y <= 638))
    sprite = SPR_MENU_Q;
  sfSprite_setPosition(explo->sprite[sprite], vec);
  sfRenderWindow_drawSprite(explo->graph->window,
			    explo->sprite[sprite], NULL);
}

void		draw_clicked_menu(t_explo *explo, sfVector2f vec,
				  int sprite)
{
  if (sprite != -1)
    {
      sfSprite_setPosition(explo->sprite[sprite], vec);
      sfRenderWindow_drawSprite(explo->graph->window,
				explo->sprite[sprite], NULL);
      sfRenderWindow_display(explo->graph->window);
      while (!sfKeyboard_isKeyPressed(sfKeySpace));
    }
}

int		click_menu(t_explo *explo, sfVector2i click,
			   sfVector2f vec)
{
  int		sprite;

  sprite = -1;
  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      if ((click.x >= 264 && click.x <= 460)
	  && (click.y >= 446 && click.y <= 609))
	sprite = SPR_HELP;
      else if ((click.x >= 1003 && click.x <= 1282)
	       && (click.y >= 175 && click.y <= 367))
	return (2);
      else if ((click.x >= 723 && click.x <= 957)
	       && (click.y >= 456 && click.y <= 638))
	sprite = SPR_SOON;
      else if ((click.x >= 85 && click.x <= 273)
	       && (click.y >= 232 && click.y <= 382))
	sprite = SPR_OPT;
      else if ((click.x >= 1023 && click.x <= 1147)
	       && (click.y >= 543 && click.y <= 638))
	return (1);
      draw_clicked_menu(explo, vec, sprite);
    }
  return (SUCCESS);
}

int		menu(t_explo *explo)
{
  sfVector2f	vec;
  sfVector2i	click;
  int		ret;

  vec = vector2f(explo->player->pos.x - (SCREEN_WIDTH / 2),
		 explo->player->pos.y - (SCREEN_HEIGHT / 2));
  sfMusic_setLoop(explo->music[SND_MENU], sfTrue);
  sfMusic_play(explo->music[SND_MENU]);
  while (1)
    {
      click = sfMouse_getPositionRenderWindow(explo->graph->window);
      if ((get_event() == ESCAPE
	   && !wait_key(explo->graph->window, sfKeyEscape))
	  || (ret = click_menu(explo, click, vec)) == 1)
	return (1);
      if (ret == 2)
	break;
      draw_menu(explo, click, vec);
      sfRenderWindow_display(explo->graph->window);
    }
  sfMusic_stop(explo->music[SND_MENU]);
  return (SUCCESS);
}
