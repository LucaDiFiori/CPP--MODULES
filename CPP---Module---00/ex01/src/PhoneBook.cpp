/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 10:27:34 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 10:27:34 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.class.hpp"

//constructor - destructor
PhoneBook::PhoneBook()
{
	this->_nbContacts = 0;
	PhoneBook::start();
};

PhoneBook::~PhoneBook()
{
	std::cout << GREEN "Goodbye!" << std::endl;
};

//start method
void PhoneBook::start(void)
{
	std::cout << RED "WELCOME TO THE PHONEBOOK!" << std::endl;
	std::cout << GREEN "-> add up to 8 contacts." << std::endl;
	std::cout << GREEN "-> search for a contact by typing 'SEARCH'." << std::endl;
	std::cout << GREEN "-> add a contact by typing 'ADD'." << std::endl;
	std::cout << GREEN "-> exit the PhoneBook by typing 'EXIT'." << std::endl;
};


// NOTE: std::ws: This is a manipulator that tells the input stream to discard 
//       any leading whitespace (such as spaces, tabs, or newlines) before 
//       processing the next input. It's important to note that std::ws only 
//       skips leading whitespace characters; it doesn't affect any other 
//       characters in the input.
void PhoneBook::addName(int index)
{
	std::string name;

	while (true)
	{
    	std::cout << BLUE "Enter the name: " << std::endl;
    	std::getline(std::cin >> std::ws, name);
    	if (name.empty() || name == "\"\"")
    	{
        	std::cout << RED "Not valid! Please try again." << std::endl;
    	}
    	else
    	{
        	this->_contacts[index].setFirstName(name);
        	break;
    	}
	}
}

void PhoneBook::addLastName(int index)
{
    std::string lastName;

    while (true)
    {
        std::cout << BLUE "Enter the last name: " << std::endl;
        std::getline(std::cin >> std::ws, lastName);
        if (lastName.empty() || lastName == "\"\"")
        {
            std::cout << RED "Not valid! Please try again." << std::endl;
        }
        else
        {
            this->_contacts[index].setLastName(lastName);
            break;
        }
    }
}

void PhoneBook::addNickName(int index)
{
    std::string nickName;

    while (true)
    {
        std::cout << BLUE "Enter the nickname: " << std::endl;
        std::getline(std::cin >> std::ws, nickName);
        if (nickName.empty() || nickName == "\"\"")
        {
            std::cout << RED "Not valid! Please try again." << std::endl;
        }
        else
        {
            this->_contacts[index].setNickName(nickName);
            break;
        }
    }
}

// std::ws is an input manipulator that is used to ignore leading whitespace 
// characters in an input stream. When used with an input stream like std::cin, 
// std::ws skips over any whitespace characters (such as spaces, tabs, or newlines) 
// until it encounters the first non-whitespace character.
void PhoneBook::addPhoneNumber(int index)
{
	std::string phoneNumber;

    while (true) 
	{
        std::cout << BLUE "Enter the phone number: " << std::endl;
        std::getline(std::cin >> std::ws, phoneNumber);
        if (Utils::isDigitsOnly(phoneNumber)) 
		{
            this->_contacts[index].setPhoneNumber(phoneNumber);
            break;
        } 
		else
            std::cout << RED "Error: Phone number must contain only digits. Please try again." << std::endl;
    }
}


void PhoneBook::addDarkSecret(int index)
{
    std::string darkSecret;

    while (true)
    {
        std::cout << BLUE "Enter the darkest secret: " << std::endl;
        std::getline(std::cin >> std::ws, darkSecret);
        if (darkSecret.empty() || darkSecret == "\"\"")
        {
            std::cout << RED "Not valid! Please try again." << std::endl;
        }
        else
        {
            this->_contacts[index].setDarkSecret(darkSecret);
            break;
        }
    }
}

//Add method
void PhoneBook::add(void)
{
    static int overwriteIndex = 0;
    int index;

    if (this->_nbContacts >= 8)
    {
        std::cout << RED "The PhoneBook is full!" << std::endl;
        std::cout << RED "This contact will replace the oldest one in the list." << std::endl;
        index = overwriteIndex;
        overwriteIndex = (overwriteIndex + 1) % 8;
    }
    else
    {
        index = this->_nbContacts;
        this->_nbContacts++;
    }
    PhoneBook::addName(index);
    PhoneBook::addLastName(index);
    PhoneBook::addNickName(index);
    PhoneBook::addPhoneNumber(index);
    PhoneBook::addDarkSecret(index);
    std::cout << GREEN "Contact added successfully!" << std::endl;
}


//Search method
void PhoneBook::search(void)
{
    if (this->_nbContacts == 0)
    {
        std::cout << RED "The PhoneBook is empty!" << std::endl;
        return;
    }
}







void PhoneBook::getContact(int index) const
{
	std::cout << "name : " << this->_contacts[index].getFisrtName() << std::endl;
	std::cout << "last name : " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "nickname : " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "phone number : " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "dark secret :" << this->_contacts[index].getDarkSecret() << std::endl;
	std::cout << std::endl;
};