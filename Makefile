##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

all:	zappy_ai zappy_gui zappy_server

zappy_ai:
	make -C client_zappy/

zappy_gui:
	make -C gui_zappy/

zappy_server:
	make -C server/

clean:
	make clean -C client_zappy/
	make clean -C gui_zappy/
	make clean -C server/

fclean:	clean
	make fclean -C client_zappy/
	make fclean -C gui_zappy/
	make fclean -C server/

re:	fclean all

.PHONY: all zappy_ai zappy_gui zappy_server clean fclean re
