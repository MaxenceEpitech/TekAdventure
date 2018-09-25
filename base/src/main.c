/*
** main.c for tekadventure in /home/camille/semestre2/tekadventure
** 
** Made by camille
** Login   <camille.arbault@epitech.eu>
** 
** Started on  Wed Aug 16 15:00:42 2017 camille
** Last update Wed Aug 30 15:07:03 2017 jean-baptiste
*/

#include <stdlib.h>
#include "tek.h"

int	main()
{
  t_materials	*mats;

  if ((mats = malloc(sizeof(t_materials))) == NULL)
    return (84);
  if ((mats = prepare_game(mats)) == NULL)
    return (84);
  return (begin_game(mats));
}
