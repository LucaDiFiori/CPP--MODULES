/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 09:54:57 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 09:54:57 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.class.hpp"

// Constructor
Contact::Contact()
{
};

// Setters
std::string Contact::getFisrtName() const
{
	return (this->_firstName); 
};

std::string Contact::getLastName() const
{
	return (this->_lastName);
};

std::string Contact::getNickName() const
{
	return (this->_nickName);
};

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
};

std::string Contact::getDarkSecret() const
{
	return (this->_darkSecret);
};

// Getters
void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
};

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
};

void	Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
};

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
};

void	Contact::setDarkSecret(std::string darkSecret)
{
	this->_darkSecret = darkSecret;
};