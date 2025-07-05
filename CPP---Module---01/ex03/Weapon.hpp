/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:37:46 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:37:46 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

/**
 * Class: Weapon
 * --------------
 * Represents a weapon that has a specific type. The weapon's type can be set 
 * and retrieved using the provided methods.
 *
 * Members:
 *  - _type: A private string representing the type of the weapon (e.g., "Sword", "Axe").
 *
 * Functions:
 *  - const std::string& getType() const:
	     Note: 
		*   - const std::string&: This means the function returns a constant 
		*		 				  reference to a string (cannot be modified).
		*   - const: This means that the function does not modify the object's state.
 *      
 *  - void setType(std::string newType):
 *      Sets a new type for the weapon. The new type is passed as a string parameter 
 *      and replaces the current weapon type.
 *
 * Usage:
 *  - The `Weapon` class can be used to create weapon objects with a specified type 
 *    that can be accessed or changed during the program execution. It ensures that 
 *    each weapon has a valid type set and offers functions to manage it.
 *  - Example usage: 
 *      Weapon sword("Sword"); // Creates a weapon with the type "Sword".
 *      std::cout << sword.getType(); // Outputs: Sword
 *
 * Notes:
 *  - const std::string& getType() const: The function returns a constant reference 
 *    to ensure that the type cannot be modified when accessed. It also guarantees 
 *    that the function doesn't change the state of the Weapon object.
 */
class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string& getType() const;
		void setType(std::string newType);
};

#endif