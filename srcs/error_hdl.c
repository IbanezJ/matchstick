/*
** game_phase.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Feb 14 15:15:50 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 23 14:30:31 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	error_reduc(int	line, int matches)
{
  if (line == -3)
    return (-3);
  if (matches == -2)
    return (84);
  return (0);
}

int	remove_matches(char **map, int rank_last, int *info)
{
  int	i;
  int	j;
  int	compt;

  compt = 0;
  while (compt < info[1])
    {
      map[info[0]][rank_last] = ' ';
      rank_last--;
      compt++;
    }
  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == '|')
	    return (0);
	  j++;
	}
      j = 0;
      i++;
    }
  return (1);
}

int	*full_error_info(char **map, int *info, int max_remove, int nb_line)
{
  char	*line;

  while (error_matches(map, info[1], info[0], max_remove) == 84)
    {
      my_printf("Line: ");
      info[0] = my_getnbr((line = get_next_line(0)));
      if (info[0] == -3)
	return (info);
      while (error_line(map, info[0], nb_line) == 84)
	{
	  my_printf("Line: ");
	  info[0] = my_getnbr((line = get_next_line(0)));
	  if (info[0] == -3)
	    return (info);
	}
      my_printf("Matches: ");
      info[1] = my_getnbr((line = get_next_line(0)));
    }
  return (info);
}

int	*choose_atk(int *info, char **map, int max_remove, int nb_line)
{
  char	*line;

  info[0] = my_getnbr((line = get_next_line(0)));
  if (info[0] == -3)
    return (info);
  while (error_line(map, info[0], nb_line) == 84)
    {
      my_printf("Line: ");
      info[0] = my_getnbr((line = get_next_line(0)));
      if (info[0] == -3)
	return (info);
    }
  free(line);
  my_printf("Matches: ");
  info[1] = my_getnbr((line = get_next_line(0)));
  info = full_error_info(map, info, max_remove, nb_line);
  free(line);
  return (info);
}
