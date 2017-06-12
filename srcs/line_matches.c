/*
** line_matches.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Wed Feb 22 12:01:08 2017 Jean-Alexandre IBANEZ
** Last update Wed Feb 22 12:03:44 2017 Jean-Alexandre IBANEZ
*/

#include "my.h"

int	error_line(char **map, int line, int nb_line)
{
  if (line == -3)
    return (-3);
  if (line == -2)
    return (84);
  if (line == -1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  if ((!(map[line])) || line < 1 || line > nb_line)
    {
      my_printf("Error: this line is out of range\n");
      return (84);
    }
  return (0);
}

int	error_matches(char **map, int matches, int line, int max_remove)
{
  if (error_reduc(line, matches) != 0)
    return (error_reduc(line, matches));
  if (matches == -1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (84);
    }
  if (matches > max_remove)
    {
      my_printf("Error: you cannot remove more than %d matches per turn\n",
		max_remove);
      return (84);
    }
  if (matches > matches_count(map[line]))
    {
      my_printf("Error: not enough matches on this line\n");
      return (84);
    }
  if (matches == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (84);
    }
  return (0);
}
