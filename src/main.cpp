/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "IGame.hpp"
#include "Lib.hpp"
#include "Core.hpp"

#include <unistd.h>
#include <sys/stat.h>
#include <dlfcn.h>
#include <string.h>

void display_usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade path" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tpath\t path to the graphical lib" << std::endl;
    std::cout << "EXAMPLE" << std::endl;
    std::cout << "\t./arcade ./lib/lib_arcade_sfml.so" << std::endl;
}

int check_is_dir(char *path, struct stat my_stat)
{
    if (S_ISDIR(my_stat.st_mode) == 1) {
        std::cerr << "Error: "<< path << " is a directory." << std::endl;
        return -1;
    }
    return 0;
}

int check_is_lib(char *path)
{
    std::string string_path = path;

    if (string_path.find(".so") <= 0 || string_path.find(".so") > string_path.size()) {
        std::cerr << "Error: "<< path << " is not a shared library." << std::endl;
        return -1;
    }
    return 0;
}

int error_handling(int ac, char **av)
{
    struct stat s;
    int nb = stat(av[1], &s);

    if (nb < 0 || s.st_size < 0) {
        std::cerr << "Error: "<< av[1] << " not found." << std::endl;
        return -1;
    }
    if (ac > 2) {
        std::cerr << "Error: only 1 argument is required, not " << ac - 1 << "." << std::endl;
        return -1;
    }
    nb = check_is_dir(av[1], s);
    if (nb < 0)
        return -1;
    nb = check_is_lib(av[1]);
    if (nb < 0)
        return -1;
    return 0;
}

int my_game(std::string path)
{
    int nb = 0;

    Core my_core(path);
    nb = my_core.launch();
    return nb;
}

int main(int ac, char **av)
{
    if (ac == 0) {
        display_usage();
        return 84;
    }
    if (ac == 1 || (strcmp(av[1], "-h") == 0 && ac == 2)) {
        display_usage();
        return 84;
    }
    if (error_handling(ac, av) == -1)
        return 84;
    std::string path = av[1];
    return my_game(path);
}