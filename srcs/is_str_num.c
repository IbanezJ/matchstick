/*
** is_str_num.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Feb 17 21:47:01 2017 Jean-Alexandre IBANEZ
** Last update Sat Feb 18 15:56:20 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>

int	is_str_num(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-3);
  if (str[0] == '\0')
    return (-2);
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (1);
      i++;
    }
  return (0);
}
