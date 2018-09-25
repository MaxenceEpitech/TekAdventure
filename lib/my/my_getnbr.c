/*
** my_getnbr.c for fridge in /home/killian/colle/CPE_2016_stumper3/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Mon Sep 18 14:51:23 2017 Killian
** Last update Mon Sep 18 17:10:42 2017 Killian
*/

#include <stdlib.h>

int	is_sign(char sign)
{
  if (sign == '-' || sign == '+')
    return (0);
  return (1);
}

int	is_num(char nb)
{
  if ((nb < '0' || nb > '9') && nb != '-' && nb != '+')
    return (1);
  return (0);
}

int	my_getnbr(char *nb_str)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  j = 0;
  nb = 0;
  if (nb_str == NULL)
    return (-2);
  while (is_sign(nb_str[i]) == 0 && nb_str[i] != '\0')
    {
      if (nb_str[i] == '-')
	j++;
      i++;
    }
  while (nb_str[i] != '\0')
    {
      if (is_num(nb_str[i]))
	return (-1);
      nb = nb * 10 + nb_str[i] - '0';
      i++;
    }
  if (j % 2 != 0)
    nb *= (-1);
  return (nb);
}
