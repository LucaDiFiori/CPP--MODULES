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
}

Harl::~Harl()
{
}

void Harl::_debug()
{
 	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * Function: getLogLevel
 * ----------------------
 * Converts a string representing a log level (such as "DEBUG", "INFO", "WARNING", or "ERROR") 
 * into its corresponding integer value (corrisponding to the enum Level).
 * This integer can be used in a switch statement to control which log messages are 
 * displayed based on the severity level.
 *
 * Parameters:
 *  - level: A string representing the log level. Expected values are "DEBUG", "INFO", "WARNING", or "ERROR".
 *
 * Returns:
 *  - DEBUG: If the input level is "DEBUG", returns an integer constant representing the debug level.
 *  - INFO: If the input level is "INFO", returns an integer constant representing the info level.
 *  - WARNING: If the input level is "WARNING", returns an integer constant representing the warning level.
 *  - ERROR: If the input level is "ERROR", returns an integer constant representing the error level.
 *  - -1: If the input level does not match any of the expected values, returns -1 to indicate an invalid level.
 *
 * Usage:
 *  - This function is useful for mapping string input to an integer value, making it easier to handle in 
 *    a switch-case structure.
 */
int Harl::getLogLevel(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (-1);
}

/**
 * Function: complain
 * -------------------
 * Responds to a specified log level by executing the corresponding member function to 
 * display messages associated with that log level and all levels above it. The function 
 * utilizes a switch statement to determine which log level to start from based on the input.
 *
 * Parameters:
 *  - level: A string representing the log level that dictates which messages to display.
 *           Expected values are "DEBUG", "INFO", "WARNING", or "ERROR".
 *
 * Process:
 *  - Calls the getLogLevel function to convert the input string into an integer log level.
 *  - Defines an array of pointers to member functions, each corresponding to a specific log level.
 *  - Uses a switch statement to determine the starting log level based on the result from getLogLevel:
 *    - If the log level is DEBUG, it calls the debug method and falls through to INFO, WARNING, and ERROR.
 *    - If the log level is INFO, it calls the info method and falls through to WARNING and ERROR.
 *    - If the log level is WARNING, it calls the warning method and falls through to ERROR.
 *    - If the log level is ERROR, it calls the error method.
 *  - If the log level is invalid (not among the recognized levels), it outputs an error message indicating 
 *    the unknown level and provides usage instructions.
 *
 * Usage:
 *  - This function is useful for filtering messages based on severity levels. For example, 
 *    calling complain("WARNING") will display all messages at the WARNING level and above.
 *    Example usage: harl.complain("INFO"); // Displays INFO, WARNING, and ERROR messages.
 */
void Harl::complain(std::string level)
{
	int logLevel = getLogLevel(level);
	void (Harl::*actionsPtr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	switch (logLevel)
	{
		case DEBUG:
			(this->*actionsPtr[DEBUG])();
			// fall through
		case INFO:
			(this->*actionsPtr[INFO])();
			// fall through
		case WARNING:
			(this->*actionsPtr[WARNING])();
			// fall through
		case ERROR:
			(this->*actionsPtr[ERROR])();
		break;
		default:
			std::cout << "Unknown level" << std::endl;
			std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
			break;
	}
}