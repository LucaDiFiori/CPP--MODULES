/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:38:00 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:38:00 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type =newType;
	std::cout << "New weapon obtained: " << newType << std::endl;
}