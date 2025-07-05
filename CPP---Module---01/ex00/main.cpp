/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 09:35:02 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 09:35:02 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "-->Creating a Zombie on the stack:<--" << std::endl;
	Zombie stackZombie("Stacky");
	randomChump("Chumpy");
	stackZombie.announce();



	std::cout << std::endl << "-->Creating a Zombie on the heap:<--" << std::endl;
	Zombie *heapZombie; 
	Zombie *heapZombie2;

	heapZombie = new Zombie("Heapy");
	heapZombie->announce();

	heapZombie2 = newZombie("Heapy2");
	heapZombie2->announce();

	delete heapZombie;
	delete heapZombie2;
}