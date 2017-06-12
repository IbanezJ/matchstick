/*
** my.h for matchstick in /home/ibanez_j/CPE_2016_matchstick
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Feb 13 18:01:35 2017 Jean-Alexandre IBANEZ
** Last update Fri Feb 24 19:03:54 2017 Jean-Alexandre IBANEZ
*/

#ifndef MY_H_
# define MY_H_

int     choose_matches(int matches);
int     other_ai_turn(char **map, int max_remove, int nb_line);
int     *binary(int nb);
void    disp_int(int *nb);
int     error_line(char **map, int line, int nb_line);
int     error_matches(char **map, int matches, int line, int max_remove);
int     error_reduc(int line, int matches);
int     is_str_num(char *str);
int     ai_turn(char **map, int max_remove, int nb_line);
int     matches_count(char *line);
int	remove_matches(char **map, int rank_last, int *info);
int     *choose_atk(int *info, char **map, int max_remove, int nb_line);
int	game_phase(char **map, int, int);
void	my_printf(char *str, ...);
void    disp_map(char **map);
void	my_putchar(char c);
void	my_putstr(char *str);
void    free_map(char **map);
char    **create_map(int nbr);
int     my_getnbr(char *str);

#endif
