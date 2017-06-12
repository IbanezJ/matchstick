/*
** main.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Feb 13 17:57:13 2017 Jean-Alexandre IBANEZ
** Last update Sat Feb 18 17:18:59 2017 Jean-Alexandre IBANEZ
*/

#include "my.h"

int	main(int ac, char **av)
{
  int	end;
  int	max_remove;
  int	nb_line;
  char	**map;

  end = 0;
  if (ac != 3 || is_str_num(av[1]) == 1 || is_str_num(av[2]) == 1)
    return (84);
  max_remove = my_getnbr(av[2]);
  nb_line = my_getnbr(av[1]);
  if (nb_line < 1 || nb_line > 100)
    return (84);
  map = create_map(nb_line);
  disp_map(map);
  while (end == 0)
    end = game_phase(map, max_remove, nb_line);
  if (end == 3)
    return (0);
  if (end == 1)
    my_printf("I lost... snif... but I'll get you next time!!\n");
  else
    my_printf("You lost, too bad...\n");
  return (end);
}
