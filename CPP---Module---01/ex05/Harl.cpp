/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-29 12:25:24 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-29 12:25:24 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl object created" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl object destroyed" << std::endl;
}

void Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * Function: complain
 * -------------------
 * Processes a complaint from Harl based on the provided level of severity (DEBUG, INFO, 
 * WARNING, ERROR). The function utilizes an array of pointers to member functions, allowing
 * it to avoid using multiple if/else statements. Depending on the input level, the appropriate
 * function is called.
 *
 * Parameters:
 *  - level: A string representing the complaint level. Valid values are "DEBUG", "INFO",
 *           "WARNING", and "ERROR".
 *
 * Process:
 *  - An array of function pointers, actionsPtr, is initialized to point to the Harl member 
 *    functions _debug, _info, _warning, and _error.
 *  - A second array, levels, holds the corresponding string levels to compare against the 
 *    input level.
 *  - The function iterates through the levels array, comparing each string to the input.
 *    If a match is found, the corresponding function is called using (this->*actionsPtr[i])().
 *    This syntax is required because we are using a pointer to a member function and invoking 
 *    it on the current object (this).
 *  - If no match is found, the function outputs "Invalid level".
 *
 * Usage:
 *  - This function allows Harl to complain at different levels of severity without excessive 
 *    if/else logic. It dynamically selects and invokes the appropriate complaint method.
 *  - Example usage: harl.complain("ERROR"); // Calls the error complaint function.
 */

void Harl::complain(std::string level)
{
	void (Harl::*actionsPtr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			// Note: Im are calling the member function on the current object within a member function, 
			// and this is a pointer to the current object, not the object itself.
			// So in order to call the member function, we need to use the syntax (this->*actionsPtr[i])()
			// (use when i have a pointer to an object)
			(this->*actionsPtr[i])();
			return;
		}
	}

	std::cout << "Invalid level" << std::endl;
}