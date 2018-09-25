/*
** my_putnbr.c for my_putnbr in /home/maxence.fourrier/lib/my
** 
** Made by Maxence Fourrier
** Login   <maxence.fourrier@epitech.net>
** 
** Started on  Mon Mar 13 23:09:12 2017 Maxence Fourrier
** Last update Sun Oct  8 23:02:02 2017 jean-baptiste
*/

#include "explo.h"

void	my_putnbr(int nb)
{
  int	a;

  a = 1;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return ;
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / a) >= 10)
    a = a * 10;
  while (a > 0)
    {
      my_putchar((nb / a) % 10 + '0');
      a = a / 10;
    }
}
