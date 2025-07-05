/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 09:44:47 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 09:44:47 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Function: randomChump
 * ---------------------
 * Creates a new Zombie object on the stack with a specified name, and immediately 
 * makes the Zombie announce itself by calling its announce() method.
 *
 * Parameters:
 *  - name: A string representing the name to be assigned to the Zombie.
 *
 * Process:
 *  - Instantiates a Zombie object locally (on the stack) using the provided name.
 *  - Calls the announce() method of the Zombie object to output its message to the console.
 *
 * Usage:
 *  - This function is useful for creating and announcing a Zombie quickly without 
 *    needing to manage memory allocation manually. Since the Zombie is created on 
 *    the stack, it will be automatically destroyed when the function exits.
 *  - Example usage: randomChump("Frank"); // Creates and announces a Zombie named Frank.
 *
 * Memory Management:
 *  - Since the Zombie is created on the stack, no explicit memory management is required. 
 *    The Zombie will be destroyed automatically when the function scope ends.
 */
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
	std::cout << name << ":" << " my scooope in this world is OoooOverzzz" << std::endl;
}