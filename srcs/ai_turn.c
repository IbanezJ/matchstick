/*
** ai_turn.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Feb 17 14:40:32 2017 Jean-Alexandre IBANEZ
** Last update Fri Feb 24 11:44:08 2017 Jean-Alexandre IBANEZ
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"

int	ai_turn(char **map, int max_remove, int nb_line)
{
  int	info[2];
  int	rank_last;

  rank_last = 0;
  info[0] = 0;
  info[1] = 0;
  while (matches_count(map[info[0]]) == 0)
    {
      srand((unsigned int) time(NULL));
      info[0] = rand() % (nb_line + 1 - 1) + 1;
    }
  while (map[info[0]][rank_last] != '|' ||
	 (map[info[0]][rank_last + 1] != ' ' &&
	  map[info[0]][rank_last + 1] != '*'))
    rank_last++;
  srand((unsigned int) time(NULL));
  if (max_remove > matches_count(map[info[0]]))
    info[1] = matches_count(map[info[0]]);
  else if (matches_count(map[info[0]]) > max_remove)
    info[1] = max_remove;
  if (info[1] == 0)
    info[1]++;
  my_printf("AI removed %d match(es) from line %d\n", info[1], info[0]);
  return (remove_matches(map, rank_last, info));
}
