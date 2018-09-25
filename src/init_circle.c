/*
** init_circle.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 22 23:12:57 2017 maxence.fourrier
** Last update Fri Sep 22 23:28:24 2017 maxence.fourrier
*/

#include "explo.h"

sfCircleShape	*new_circle(sfVector2f center, sfColor border,
			    float radius)
{
  sfCircleShape	*new;

  if ((new = sfCircleShape_create()) == NULL)
    return (NULL);
  sfCircleShape_setPosition(new, center);
  sfCircleShape_setFillColor(new, sfTransparent);
  sfCircleShape_setOutlineThickness(new, 5);
  sfCircleShape_setOutlineColor(new, border);
  sfCircleShape_setRadius(new, radius);
  return (new);
}

sfCircleShape	**init_circle(t_explo *explo)
{
  sfCircleShape	**circle;
  int		radius;

  if ((circle = malloc(sizeof(sfCircleShape *) * NB_CIRCLE)) == NULL)
    return (NULL);
  if ((circle[0] = new_circle(vector2f(((explo->game->size.x / 2)
					* SPRITE_FLOOR_SIZE) - (BASE_X / 2)
				       - RADIUS_CIRCLE_HOME + 100,
				       ((explo->game->size.y / 2)
					* SPRITE_FLOOR_SIZE) - (BASE_Y / 2)
				       - RADIUS_CIRCLE_HOME + 120),
			      sfGreen, RADIUS_CIRCLE_HOME)) == NULL)
    return (NULL);
  circle[1] = NULL;
  return (circle);
}
