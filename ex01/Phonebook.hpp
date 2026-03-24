/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:26:41 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/24 15:38:40 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include "Contact.hpp"

class Phonebook {

private:
	Contact contacts[9];
	int 	index = 1;
	std::string formatColumn(std::string str) const {
		if(str.length() > 10)
			return str.substr(0, 9) + ".";
		else
		{
			int spacesNeeded = 10 - str.length();
			std::string spaces(spacesNeeded, ' ');
			return spaces + str;
		}
	}

public:
	void addContact(Contact c);
	void displayContact() const;
};

void contact_successfull();
void user_prompt(bool isvalid, std::string &input);

#endif
