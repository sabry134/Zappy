##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

NAME	=	../zappy_server

SRCS	=	src/commands/graphical/graphical_bct.c \
			src/commands/graphical/graphical_mct.c \
			src/commands/graphical/graphical_msz.c \
			src/commands/graphical/graphical_pin.c \
			src/commands/graphical/graphical_plv.c \
			src/commands/graphical/graphical_ppo.c \
			src/commands/graphical/graphical_sgt.c \
			src/commands/graphical/graphical_sst.c \
			src/commands/graphical/graphical_tna.c \
			src/commands/player/player_broadcast_dir_hor.c \
			src/commands/player/player_broadcast.c \
			src/commands/player/player_connect_nbr.c \
			src/commands/player/player_eject.c \
			src/commands/player/player_fork.c \
			src/commands/player/player_forward.c \
			src/commands/player/player_incantation.c \
			src/commands/player/player_inventory.c \
			src/commands/player/player_left.c \
			src/commands/player/player_look.c \
			src/commands/player/player_right.c \
			src/commands/player/player_set.c \
			src/commands/player/player_take.c \
			src/commands/commands_parse.c \
			src/game/egg.c \
			src/game/game_loop.c \
			src/game/incantation.c \
			src/game/player.c \
			src/game/resources.c \
			src/game/time.c \
			src/graphical/events/graphical_ebo.c \
			src/graphical/events/graphical_edi.c \
			src/graphical/events/graphical_enw.c \
			src/graphical/events/graphical_pbc.c \
			src/graphical/events/graphical_pdi.c \
			src/graphical/events/graphical_pdr.c \
			src/graphical/events/graphical_pex.c \
			src/graphical/events/graphical_pfk.c \
			src/graphical/events/graphical_pgt.c \
			src/graphical/events/graphical_pic.c \
			src/graphical/events/graphical_pie.c \
			src/graphical/events/graphical_pnw.c \
			src/graphical/events/graphical_seg.c \
			src/graphical/graphical_join.c \
			src/graphical/graphical_write.c \
			src/network/client_read.c \
			src/network/client.c \
			src/network/server_listen.c \
			src/network/server_read.c \
			src/network/server.c \
			src/args_handling.c \
			src/args.c \
			src/help.c \
			src/main.c \
			src/signal.c \
			src/teams.c \
			src/utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
