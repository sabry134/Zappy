/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-nathan.warin
** File description:
** Errors.hpp
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

#include <iostream>

class Errors : public std::exception {
    private:
    public:
        class NotEnoughArgumentsError {
            private:
                const std::string message = "Not enough arguments";
            public:
                const char *what() const throw();
                
        };
        class ArgumentNotANumber {
            private:
                const std::string message = "Argument is not a number";
            public:
                const char *what() const throw();
        };
        class ArgumentError {
            private:
                const std::string message = "Only first argument should be a float or too much '.' in argument";
            public:
                const char *what() const throw();
        };
};

#endif