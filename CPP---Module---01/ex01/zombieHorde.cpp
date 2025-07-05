/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 14:59:12 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 14:59:12 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Function: zombieHorde
 * ---------------------
 * Creates an array (horde) of Zombies dynamically, with each Zombie initialized to 
 * have the same specified name using the `setName()` method. The function returns a 
 * pointer to the first element of the Zombie array, allowing access to the entire horde.
 *
 * Parameters:
 *  - N: The number of Zombies to create in the horde.
 *  - name: A string representing the name to be assigned to each Zombie in the horde.
 *
 * Process:
 *  - Dynamically allocates an array of N Zombie objects using the 'new' operator.
 *  - The `new Zombie[N]` expression allocates memory for an array of N Zombies.
 *  - Each Zombie object is then initialized using the `setName()` method, which assigns 
 *    the same name (passed as a parameter) to all Zombies in the horde.
 *  - Returns a pointer to the first element of the Zombie array, which can be used 
 *    to access and manage the entire horde.
 *
 * NOTE. horde = new Zombie[N];
 * - The expression new Zombie[N] dynamically allocates an array of N Zombie objects 
 *   on the heap. This means it reserves enough memory to store N instances of the Zombie class.
 * - The new operator also calls the default constructor for each Zombie in the array. 
 *   If you have a custom default constructor (i.e., Zombie::Zombie()), it will be 
 *   invoked for each Zombie object.
 * - after the array is created, the function iterates over each Zombie object in the
 *   array and initializes it with the provided name using the setName() method.
 *
 * Usage:
 *  - This function is useful when you need to create multiple Zombies at once and 
 *    manage them as a group. Since the Zombies are allocated dynamically, the caller 
 *    is responsible for freeing the memory once the horde is no longer needed.
 *  - Example usage: Zombie* horde = zombieHorde(5, "Fred"); // Creates a horde of 5 Zombies named Fred.
 *
 * Memory Management:
 *  - Since the Zombie array is created using the 'new' operator, the caller must 
 *    explicitly delete the entire array using `delete[]` to avoid memory leaks.
 *    Example: delete[] horde;
 */
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	if (N <= 0)
		return (NULL);
		
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}