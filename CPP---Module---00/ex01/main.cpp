/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 10:34:52 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 10:34:52 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PhoneBook.class.hpp"



int main()
{
	PhoneBook phoneBook;
	std::string cmd;

	while (true)
	{
		std::cout <<BLUE "Enter a command: " << std::endl;
		std::getline(std::cin >> std::ws, cmd);
		if (cmd == "ADD")
			phoneBook.add();
		else if (cmd == "EXIT")
			break;
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "SHOW")
		{
			int i = 0;
			while (i < 8)
			{
				std::cout <<WHITE "Contact " << i << std::endl;
				phoneBook.getContact(i);
				i++;
			}
		}

		else 
			std::cout << RED "Command not found" << std::endl;

	}

};