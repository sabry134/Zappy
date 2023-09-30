/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** main
*/

#include "Gui.hpp"
#include <random>
void printUsage()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int main(int ac, char **av)
{
    srand(time(NULL));
    try {
        Gui gui(ac, av);
        gui.initGui();
        gui.guiLoop();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        printUsage();
        return 84;
    }
}
