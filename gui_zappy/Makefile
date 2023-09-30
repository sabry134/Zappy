##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

CC =	g++

SRCNAME =	main	\
			Gui		\
			GetOpt	\
			Interface	\
			Map	\
			ServerCommunication\
			Player\
			FunctionManager\
			ParseCommands\
			Team\
			Incantation\
			Egg\
			Broadcast\


SRC =	$(addprefix src/, $(addsuffix .cpp, $(SRCNAME)))
OBJ =	$(SRC:.cpp=.o)

SFML	= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-network 
CFLAGS	=	-W -Wall -Wextra
CPPFLAGS +=	-I include -fno-gnu-unique $(SFML) -lsfml-system

NAME =	zappy_gui

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@mv $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
