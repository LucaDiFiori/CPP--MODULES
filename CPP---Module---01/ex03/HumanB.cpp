/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:44:12 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:44:12 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

/*
 * This method sets the '_weapon' pointer to point to the given 'newWeapon' reference. 
 * The address of 'newWeapon' is assigned to '_weapon', allowing the HumanB object to 
 * reference the provided Weapon. It is important to note that 'newWeapon' must remain 
 * valid for the lifetime of the HumanB object to avoid dangling pointers.
 */
void HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}

/*
 * This method outputs a message indicating the attack action of the HumanB instance.
 * It first checks if '_weapon' is not null; if valid, it uses 'this->_weapon->getType()' 
 * to access the type of the Weapon, utilizing the '->' operator since '_weapon' is a 
 * pointer to a Weapon object. If '_weapon' is null, it indicates that the HumanB is 
 * unarmed.
 */
void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}