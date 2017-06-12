/*
** matches_count.c for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Feb 17 21:55:53 2017 Jean-Alexandre IBANEZ
** Last update Fri Feb 24 19:04:28 2017 Jean-Alexandre IBANEZ
*/

int	matches_count(char *line)
{
  int	compt;
  int	i;

  compt = 0;
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '|')
	compt++;
      i++;
    }
  return (compt);
}

int	choose_matches(int matches)
{
  if (matches == 7)
    matches = 1;
  else if (matches == 6)
    matches = 2;
  else if (matches == 5)
    matches = 4;
  else if (matches == 4)
    matches = 8;
  else if (matches == 3)
    matches = 16;
  else if (matches == 2)
    matches = 32;
  else if (matches == 1)
    matches = 64;
  else if (matches == 0)
    matches = 128;
  return (matches);
}
