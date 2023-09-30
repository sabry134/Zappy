/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-nathan.warin
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

const char *Errors::NotEnoughArgumentsError::what() const noexcept
{
    return (message.c_str());
}

const char *Errors::ArgumentNotANumber::what() const noexcept
{
    return (message.c_str());
}

const char *Errors::ArgumentError::what() const noexcept
{
    return (message.c_str());
}
