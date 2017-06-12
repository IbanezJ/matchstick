/*
** disp_map.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Feb 13 17:57:00 2017 Jean-Alexandre IBANEZ
** Last update Fri Feb 17 13:01:52 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	*full_line(int nbr, int value_malloc, int i, char *line)
{
  int	compt;

  compt = 0;
  if (i == 0 || i == nbr + 1)
    {
      while (compt < value_malloc - 1)
	line[compt++] = '*';
      line[compt] = '\0';
    }
  else
    {
      line[compt++] = '*';
      while (compt < value_malloc - 2)
	{
	  if (compt == (value_malloc - 1) / 2 ||
	      (compt >= (value_malloc - 1) / 2 - i + 1
	       && compt <= (value_malloc - 1) / 2 + i - 1))
	    line[compt++] = '|';
	  else
	    line[compt++] = ' ';
	}
      line[compt] = '*';
      line[++compt] = '\0';
    }
  return (line);
}

char	**create_map(int nbr)
{
  int	value_malloc;
  int	i;
  char	**map;

  value_malloc = nbr + nbr - 1 + 2 + 1;
  i = 0;
  map = malloc(sizeof(char*) * (nbr + 3));
  while (i < (nbr + 3) - 1)
    {
      map[i] = malloc(sizeof(char) * (value_malloc));
      map[i] = full_line(nbr, value_malloc, i, map[i]);
      i++;
    }
  map[i] = NULL;
  return (map);
}

void	disp_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_printf("%s\n", map[i]);
      i++;
    }
}

void	free_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      free(map[i]);
      i++;
    }
  free(map);
}
