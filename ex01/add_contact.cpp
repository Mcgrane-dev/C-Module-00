/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:00:42 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/24 16:08:59 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void Phonebook::addContact(Contact c)
{
	contacts[index] = c;
	index++;
	if (index > 8)
		index = 1;
}

void Phonebook::displayContacts() const
{
	int i = 1;
	std::string spaces(9, ' ');
	
	while(i < 9)
	{
		Contact c = contacts[i];
		std::cout << "\n" << "|" << spaces << c.getIndex() << "|" << formatColumn(c.getFirstName()) << "|"
		<< formatColumn(c.getLastName()) << "|" << formatColumn(c.getNickName()) << "|" << "\n";
		i++;
	}
}

void contact_successfull()
{
	int	i = 0;
	std::string msg = "\n--- CONTACT SUCCESSFULLY ADDED! ---\n\n";

	while(msg[i])
	{
		std::cout << msg[i] << std::flush;
		i++;
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void user_prompt(bool isvalid, std::string &input)
{
	size_t i = 0;
	static size_t j = 0;
	std::string prompts[] = {
		"Enter First Name ------: ",
		"Enter Last Name -------: ",
		"Enter Nickname --------: ",
		"Enter Phone number ----: ",
		"Enter Darkest Secret --: "
	};
	while(isvalid == true)
	{
		std::cout << prompts[j];
		std::getline(std::cin, input);
		if(input.length() == 0)
		{
			std::cout << "No empty fields!\n";
			continue;
		}
		for(i = 0; input[i]; i++)
		{
			if(j == 3)
			{
				if((!isdigit(input[i]) && input[i] != '-') || input.length() > 15)
				{
					std::cout << "Invalid!\n";
					break;
				}
			}
			else if(j == 4)
			{
				if(!isalpha(input[i]) && input[i] != ' ' && !isdigit(input[i]))
				{
					std::cout << "Invalid Character Found!\n";
					break;	
				}
			}
			else if(!isalpha(input[i]) && input[i] != ' ')
			{
				std::cout << "Invalid Character Found!\n";
				break;
			}
		}
		if(i == input.length())
		{
			isvalid = false;
			j++;
		}
	}
	if (j == 5)
		j = 0;
}