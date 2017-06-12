/*
** other_ai_turn.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Feb 23 15:19:06 2017 Jean-Alexandre IBANEZ
** Last update Sat Feb 25 12:56:16 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	count_line(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    i++;
  return (i);
}

int	removed(char **map, int line, int matches, int max_remove)
{
  int	info[2];
  int	rank_last;

  rank_last = 0;
  matches = choose_matches(matches);
  info[0] = line;
  info[1] = matches;
  if  (matches > max_remove)
    matches = max_remove;
  while (map[info[0]][rank_last] != '|' ||
	 (map[info[0]][rank_last + 1] != ' ' &&
	  map[info[0]][rank_last + 1] != '*'))
    rank_last++;
  my_printf("AI removed %d match(es) from line %d\n", info[1], info[0]);
  return (remove_matches(map, rank_last, info));
}

int	remove_one(char **map, int line)
{
  int	info[2];
  int	rank_last;

  rank_last = 0;
  while (map[line][rank_last] != '|' ||
	 (map[line][rank_last + 1] != ' ' &&
	  map[line][rank_last + 1] != '*'))
    rank_last++;
  info[0] = line;
  info[1] = 1;
  my_printf("AI removed %d match(es) from line %d\n", info[1], info[0]);
  return (remove_matches(map, rank_last, info));
}

int	choose_line_matches(int *result_xor, int **piles, char **map,
			    int max_remove)
{
  int	nb_line;
  int	j;
  int	i;

  nb_line = count_line(map) - 2;
  j = 0;
  i = 0;
  while (result_xor[i] != -1)
    {
      if (result_xor[i] == 1)
	{
	  while (j != nb_line)
	    {
	      if (piles[j][i] == 1)
		return (removed(map, j + 1, i, max_remove));
	      j++;
	    }
	}
      j = 0;
      i++;
    }
  i = 1;
  while (matches_count(map[i]) == 0)
    i++;
  return (remove_one(map, i));
}

int	other_ai_turn(char **map, int max_remove, int nb_line)
{
  int	j;
  int	i;
  int	**piles;
  int	*result_xor;

  j = 0;
  piles = malloc(sizeof(int*) * nb_line);
  result_xor = malloc(sizeof(int) * 9);
  result_xor[8] = -1;
  i = 0;
  while (i != nb_line)
    {
      piles[i] = binary(matches_count(map[i + 1]));
      i++;
    }
  i = 0;
  while (i != 8)
    {
      while (j != nb_line)
	result_xor[i] = result_xor[i] ^ piles[j++][i];
      j = 0;
      i++;
    }
  return (choose_line_matches(result_xor, piles, map, max_remove));
}
