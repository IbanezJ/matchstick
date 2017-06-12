/*
** getnbr.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Tue Jan 31 18:01:12 2017 Benjamin BRIHOUM
** Last update Sat Feb 18 15:57:22 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	my_getnbr(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  if (is_str_num(str) == -3)
    return (-3);
  if (is_str_num(str) == -2)
    return (-2);
  if (is_str_num(str) == 1)
    return (-1);
  while (str[a] != '\0')
    b = (str[a++] - 48) + (10 * b);
  return (b);
}
