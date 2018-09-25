/*
** conso_module.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Sep 29 20:50:34 2017 maxence.fourrier
** Last update Sun Oct  8 10:55:51 2017 maxence.fourrier
*/

#include "explo.h"

void		check_conso_type_other(t_explo *explo, t_placed_mod *placed,
				       int burn_time)
{
  if (placed->inv[0][1]->item > 0 && placed->furnace.y)
    placed->inv[0][1]->item--;
  if (placed->inv[0][1]->quantity > 0 && placed->furnace.y
      && placed->inv[0][1]->item <= 0)
    {
      placed->inv[0][1]->item = burn_time;
      placed->inv[0][1]->quantity--;
    }
  if (placed->inv[0][1]->quantity == 0
      && placed->inv[0][1]->item == 0)
    placed->furnace.y = 0;
}

void		check_conso_type(t_explo *explo, t_placed_mod *placed,
				 int burn_time)
{
  if (placed->inv[0][0]->item > 0 && placed->furnace.x)
    placed->inv[0][0]->item--;
  if (placed->inv[0][0]->quantity > 0 && placed->furnace.x
      && placed->inv[0][0]->item <= 0)
    {
      placed->inv[0][0]->item = burn_time;
      placed->inv[0][0]->quantity--;
    }
  if (placed->inv[0][0]->quantity == 0
      && placed->inv[0][0]->item == 0)
    placed->furnace.x = 0;
  check_conso_type_other(explo, placed, burn_time);
}

void		check_prod_fusion(t_explo *explo, t_placed_mod *placed,
				 int prod_time)
{
  if (placed->furnace.x == 1
      && explo->player->base_power < FUSION_CONSO)
    placed->furnace.x = 0;
  else if (placed->furnace.x
	   && explo->player->base_power >= FUSION_CONSO
	   && placed->inv[0][0]->quantity < FUSION_PROD_TIME)
    {
      explo->player->base_power -= FUSION_CONSO;
      placed->inv[0][0]->quantity++;
    }
  else if (placed->furnace.x
	   && placed->inv[0][0]->quantity >= FUSION_PROD_TIME
	   && placed->inv[0][0]->item < STACK_SIZE)
    {
      placed->inv[0][0]->quantity = 0;
      placed->inv[0][0]->item++;
    }
}

void		check_conso_module(t_explo *explo, t_placed_mod *placed)
{
  while (placed != NULL)
    {
      if (placed->type == MODULE_COAL)
        check_conso_type(explo, placed, COAL_BURN_TIME);
      if (placed->type == MODULE_NUCLEAR)
        check_conso_type(explo, placed, NUCLEAR_BURN_TIME);
      if (placed->type == MODULE_FUSION)
        check_prod_fusion(explo, placed, FUSION_PROD_TIME);
      placed = placed->next;
    }
}
