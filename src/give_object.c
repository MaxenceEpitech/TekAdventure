/*
** give_object.c for tekadv in /home/maxence.fourrier/Documents/Project_C/tekadv/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Oct  5 01:09:34 2017 maxence.fourrier
** Last update Thu Oct 12 19:08:25 2017 maxence.fourrier
*/

#include "explo.h"

static t_ptr_line	g_utils[10] =
  {
    {"give", detect_element},
    {"time", change_time},
    {"clear", clear_elements},
    {"help", print_help_console},
    {"exit", exit_console},
    {"health", give_health},
    {"power", give_power},
    {"oxygen", give_oxygen},
    {NULL}
  };

static t_ptr_line	g_element[30] =
  {
    {"rock", add_item_inv_console},
    {"coal", add_item_inv_console},
    {"iron", add_item_inv_console},
    {"copper", add_item_inv_console},
    {"lithium", add_item_inv_console},
    {"uranium", add_item_inv_console},
    {"titanium", add_item_inv_console},
    {"iridium", add_item_inv_console},
    {"carbon", add_item_inv_console},
    {"glass", add_item_inv_console},
    {"sand", add_item_inv_console},
    {"antimatter", add_item_inv_console},
    {"health", add_item_inv_console},
    {"solar_panel", add_item_inv_console},
    {"coal_factory", add_item_inv_console},
    {"launcher", add_item_inv_console},
    {"nuclear_reactor", add_item_inv_console},
    {"fusion_reactor", add_item_inv_console},
    {"chest", add_item_inv_console},
    {"drill", add_item_inv_console},
    {NULL}
  };

int		check_tab_give(char **tab)
{
  if (tab[1] == NULL)
    {
      my_putstr(GIVE_ELEMENT);
      my_putstr(GIVE_USAGE);
    }
  else if (my_strcmp(tab[1], "list"))
    return (1);
  else if (tab[2] == NULL)
    {
      my_putstr(GIVE_AMOUNT);
      my_putstr(GIVE_USAGE);
    }
  else if (is_num(tab[2]) == ERROR)
    {
      my_putstr(tab[2]);
      my_putstr(UNVALID_AMOUNT);
    }
  else
    return (SUCCESS);
  return (ERROR);
}

int		check_add_elem_inv(char **tab, t_explo *explo,
				   int i)
{
  int		nb;
  int		gave;

  nb = i;
  if (nb > 12)
    nb += 7;
  if (my_strcmp(tab[1], g_element[i].str))
    {
      if ((gave = g_element[i].fnc(explo->player->inv,
				   nb, atoi(tab[2]))))
	{
	  my_putnbr(gave);
	  my_putstr(SPACE);
	  my_putstr(g_element[i].str);
	  my_putstr(ADDED_INV);
	  return (SUCCESS);
	}
      else
	{
	  my_putstr(GIVE_CANT);
	  return (SUCCESS);
	}
    }
  return (1);
}

int		put_all_element()
{
  int		i;
  int		nb;

  i = -1;
  nb = 0;
  while (g_element[++i].str)
    {
      if (nb > 3)
	{
	  nb = 0;
	  my_putchar('\n');
	}
      my_putstr(g_element[++i].str);
      if (g_element[i + 1].str)
	my_putstr(", ");
      nb++;
    }
  if (nb != 0)
    my_putchar('\n');
  return (SUCCESS);
}

int		detect_element(char **tab, t_explo *explo)
{
  int		i;

  i = -1;
  if (check_tab_give(tab) == ERROR)
    return (SUCCESS);
  if (check_tab_give(tab) == 1)
    return (put_all_element());
  while (g_element[++i].str)
    if (!check_add_elem_inv(tab, explo, i))
      return (SUCCESS);
  my_putstr(UNKNOWN_ELEM);
  i = -1;
  while (g_element[++i].str)
    {
      my_putstr("Element : ");
      my_putstr(g_element[i].str);
      my_putchar('\n');
    }
  return (SUCCESS);
}

int		detect_utils(char **tab, t_explo *explo)
{
  int		i;

  i = 0;
  if (tab[0] == NULL)
    return (SUCCESS);
  while (g_utils[i].str)
    {
      if (my_strcmp(tab[0], g_utils[i].str))
	{
	  if (g_utils[i].fnc(tab, explo) == 1)
	    return (1);
	  return (SUCCESS);
	}
      i++;
    }
  my_putstr(tab[0]);
  my_putstr(UNKNOWN_COMMAND);
  return (SUCCESS);
}
