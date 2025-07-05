/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 10:41:18 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 10:41:18 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

/*
* Weapon as a Reference: 
* ----------------------
* Since HumanA is always armed, it makes sense to use a 
* reference to Weapon. A reference ensures that HumanA always has a valid Weapon 
* and cannot exist without it. Once initialized, a reference cannot be null, 
* which guarantees that HumanA is always armed.
*
* - The constructor will accept the Weapon by reference.
* - You can store the Weapon as a reference because HumanA must always be armed, 
*   and this avoids unnecessary copying.
* 
* How HumanA changes the weapon:
* -----------------------------
*  In HumanA, even though the Weapon is passed by reference and cannot be changed 
*  to refer to a different Weapon, you can still modify the internal state of the 
*  referenced Weapon object.
*
* - The reference in HumanA keeps pointing to the same Weapon object. However, 
*   since the Weapon object itself is not const, you can change its internal _type 
*   attribute (like _type) using the setType() method.
*/
class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;

	public:
	    // Since the member _weapon is a reference, my constructor must necessarily 
		// initialize it (I won't be able to have a default constructor without initialization parameters).
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack() const;

}; 

#endif