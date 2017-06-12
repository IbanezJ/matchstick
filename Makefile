##
## Makefile for Makefile in /home/ibanez_j/CPE_2016_matchstick
## 
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
## 
## Started on  Mon Dec 12 16:39:00 2016 Jean-Alexandre IBANEZ
## Last update Mon Jun 12 11:34:39 2017 Jean-Alexandre IBANEZ
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall
CLFAGS	+= -ansi -pedantic
CFLAGS	+= -I./include

NAME	= matchstick

SRCS	= srcs/disp_map.c		\
	  srcs/getnbr.c			\
	  srcs/main.c			\
	  srcs/error_hdl.c		\
	  srcs/get_next_line.c		\
	  srcs/game_phase.c		\
	  srcs/ai_turn.c		\
	  srcs/matches_count.c		\
	  srcs/is_str_num.c		\
	  srcs/line_matches.c		\
	  srcs/transfo_int.c		\
	  srcs/other_ai_turn.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS) subsystem
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L./lib -lmy

subsystem:
	cd lib && make

subsysclean:
	cd lib && make fclean

all:  $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean subsysclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean subsysclean subsystem 
