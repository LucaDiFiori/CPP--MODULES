/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:41:50 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:41:50 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

/*
* Weapon as a Pointer: 
* ---------------------
* In this case, HumanB can be unarmed, so it makes sense to 
* use a pointer to Weapon. A pointer can be null, which allows the flexibility 
* of not assigning a weapon initially. HumanB can later be equipped with a weapon 
* via a setter method (setWeapon()).
* 
* If I had used 'Weapon _weapon' instead of 'Weapon* _weapon', 
* a Weapon object would be automatically created with the default constructor 
* when a HumanB object is instantiated. This would mean that the HumanB 
* character would always have a weapon and would not have the option to be unarmed. 
* In contrast, using 'Weapon* _weapon' allows for the weapon pointer to be null, 
* enabling the possibility of creating a HumanB character without an initial weapon.
* 
* void setWeapon(Weapon& newWeapon);
* ----------------------------------
* In the setWeapon function, the parameter is declared as Weapon& newWeapon 
* rather than Weapon* weapon or just Weapon weapon for a couple of important reasons:
* - Using Weapon& newWeapon means you're passing a reference to an existing Weapon object. 
*   This allows you to interact directly with the original Weapon without making a copy of it.
* 
* - If you used 'Weapon newWeapon', it would create a copy of the Weapon object, which 
*   is not what you want when you just need to reference the original object that 
*   the HumanB instance will use. Creating a copy could also lead to unnecessary overhead.
* 
* - If you were to use a pointer (Weapon* newWeapon), you would need to deal with 
*   the possibility of a null pointer, which adds complexity and requires extra 
*   checks in your code (e.g., verifying that the pointer is not null before dereferencing it).
*
*/
class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(std::string name);
		~HumanB();

		void setWeapon(Weapon& newWeapon);
		void attack() const;
};

#endif