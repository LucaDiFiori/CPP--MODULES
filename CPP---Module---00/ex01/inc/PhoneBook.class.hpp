/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 09:55:14 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 09:55:14 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "../inc/Contact.class.hpp"
#include "../inc/Utils.class.hpp"

# define RED	"\033[91m"
# define GREEN "\033[92m"
# define BLUE "\033[94m"
# define WHITE "\033[0m"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _nbContacts;

	public:
		//Costructor - Destructor
		PhoneBook();
		~PhoneBook();


		//Methods
		void start(void);
		void addName(int index);
		void addLastName(int index);
		void addNickName(int index);
		void addPhoneNumber(int index);
		void addDarkSecret(int index);
		void add(void);
		void search(void);
		void getContact(int index) const;		
};

#endif