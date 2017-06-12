/*
** gamee_phase.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Feb 17 12:51:08 2017 Jean-Alexandre IBANEZ
** Last update Fri Feb 24 11:47:40 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int	reduc_game(int end)
{
  if (end == 1)
    return (1);
  return (0);
}

int	game_phase(char **map, int max_remove, int nb_line)
{
  int	end;
  int	rank_last;
  int	*info;

  end = 0;
  info = malloc(sizeof(int) * 2);
  rank_last = 0;
  my_printf("\nYour turn:\nLine: ");
  info = choose_atk(info, map, max_remove, nb_line);
  if (info[1] == -3 || info[0] == -3)
    return (3);
  my_printf("Player removed %d match(es) from line %d\n", info[1], info[0]);
  while (map[info[0]][rank_last] != '|' ||
	 (map[info[0]][rank_last + 1] != ' ' &&
	  map[info[0]][rank_last + 1] != '*'))
    rank_last++;
  end = remove_matches(map, rank_last, info);
  disp_map(map);
  if  (end == 1)
    return (2);
  my_printf("\nAI's turn...\n");
  end = other_ai_turn(map, max_remove, nb_line);
  disp_map(map);
  return (reduc_game(end));
}
