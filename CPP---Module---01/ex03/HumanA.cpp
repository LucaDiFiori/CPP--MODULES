/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:41:33 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:41:33 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
 * The initialization list is used to initialize member variables before the constructor's body
 * executes. For reference members, like '_weapon', this is necessary because references must be 
 * initialized upon declaration and cannot be assigned later.
 */
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void::HumanA::attack() const
{
	std::cout << _name << " attacks with his " << this->_weapon.getType() << std::endl;
}