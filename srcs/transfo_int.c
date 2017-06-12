/*
** transfo_int.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Feb 23 14:58:47 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 23 15:29:16 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	*binary(int nb)
{
  int	j;
  int	i;
  int	*result;
  static int	bin[8] = {128, 64, 32, 16, 8, 4, 2, 1};

  j = 0;
  i = 0;
  result = malloc(sizeof(int) * 9);
  result[8] = -1;
  while (i != 8)
    {
      result[i] = nb / bin[j];
      nb = nb % bin[j];
      j++;
      i++;
    }
  return (result);
}

void	disp_int(int *nb)
{
  int	i;

  i = 0;
  while (nb[i] != -1)
    {
      my_printf("%d", nb[i]);
      i++;
    }
  my_printf("\n");
}
