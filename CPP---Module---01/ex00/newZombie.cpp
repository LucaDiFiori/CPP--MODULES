/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 09:44:31 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 09:44:31 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/**
 * Function: newZombie
 * -------------------
 * Creates a new Zombie object dynamically, assigns it a specified name, and returns 
 * a pointer to the created Zombie. This allows the Zombie to be used outside the 
 * function's scope and ensures that it persists in memory until explicitly deleted.
 *
 * Parameters:
 *  - name: A string representing the name to be assigned to the new Zombie.
 *
 * Process:
 *  - Dynamically allocates memory for a new Zombie object using the 'new' operator.
 *  - Calls the Zombie constructor with the specified name, initializing the Zombie's name attribute.
 *  - Returns a pointer to the newly created Zombie object.
 *
 * Usage:
 *  - This function is useful when you need to create Zombies that persist beyond the local 
 *    scope of a function. The returned pointer must be manually managed (i.e., deleted) to 
 *    avoid memory leaks.
 *  - Example usage: Zombie* myZombie = newZombie("George"); // Creates a Zombie named George.
 *
 * Memory Management:
 *  - Since the Zombie is created dynamically using 'new', the caller is responsible for 
 *    freeing the allocated memory using 'delete' when the Zombie is no longer needed.
 */
Zombie* newZombie(std::string name)
{
	Zombie *zombiePtr;

	zombiePtr = new Zombie(name);
	return (zombiePtr);
}