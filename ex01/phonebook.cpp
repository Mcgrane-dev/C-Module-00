/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:54 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/24 15:40:16 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook	book;
	std::string	cmd;
	std::string	input;
	int			i = 1;
	bool		isvalid = true;

	while(cmd != "EXIT")
	{
		std::cout << "***********************\n";
		std::cout << "* ADD | SEARCH | EXIT *\n";
		std::cout << "***********************\n";
		std::cout << "==> ";
		std::getline(std::cin, cmd);
		if(cmd == "ADD" || cmd == "A")
		{
			Contact c;
			isvalid = true;
			user_prompt(isvalid, input);
			c.setFirstName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setLastName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setNickName(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setPhoneNum(input);
			isvalid = true;
			user_prompt(isvalid, input);
			c.setDarkSecret(input);
			c.setIndex(i);
			book.addContact(c);
			contact_successfull();
			i++;
			if(i > 8)
				i = 1;
		}
		if(cmd == "SEARCH" || cmd == "S")
		{
			int j = 0;
			book.displayContact();
			std::string input;

			while(!(j >= 1 && j <= 8))
			{
				std::cout << "\nEnter contact index 1 - 8: ";
				std::getline(std::cin, input);
				if(input.length() > 1 ||!(input >= "1" && input <= "8"))
				{
					std::cout << "Invalid index!\n";
					continue;
				}
				j = std::stoi(input);
			}
		}
	}
	std::cout << "BYE!\n";
}

//TO DO

//rm A and S
//add spaces on first name
//display individual contacts