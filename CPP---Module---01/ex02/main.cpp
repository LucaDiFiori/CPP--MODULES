/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 15:59:07 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 15:59:07 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPtr = &string;
	std::string& stringRef = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address of the stringPtr variable: " << stringPtr << std::endl;
	/* 
	* Since a reference is just an alias for the original variable, writing &stringRef 
	* is exactly the same as writing &string. Both will return the same memory address 
	* because they refer to the same object.
	*/
	std::cout << "Memory address of the stringRef variable: " << &stringRef << std::endl;

	std::cout << std::endl;

	std::cout << "Value of the string variable: " << string << std::endl;
	std::cout << "value pointed to by stringPtr: " << *stringPtr << std::endl;
	std::cout << "Value of the stringRef variable: " << stringRef << std::endl;
}