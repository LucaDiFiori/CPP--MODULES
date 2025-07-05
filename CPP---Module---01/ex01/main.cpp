/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-27 15:17:06 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-27 15:17:06 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde;
	std::string name;
	int N;

	N = 5;
	name = "Hordie";
	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
}