/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:54 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/17 16:05:42 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

#include <iostream>

class Contact {

private:
	std::string lastName;
	std::string nickName;
	std::string phoneNum;
	std::string firstName;
	std::string darkSecret;

public:
	void setFirstName(std::string f) {
		firstName = f;
	}
	std::string getFirstName() const {
		return firstName;
	}
	void setLastName(std::string l) {
		lastName = l;
	}
	std::string getLastName() const {
		return lastName;
	}
	void setPhoneNum(std::string p) {
		phoneNum = p;
	}
	std::string getPhoneNum() const {
		return phoneNum;
	}
	void setNickName(std::string n) {
		nickName = n;
	}
	std::string getnickName() const {
		return nickName;
	}
	void setDarkSecret(std::string d) {
		darkSecret = d;
	}
	std::string getDarkSecret() const {
		return darkSecret;
	}
};

class Phonebook {

private:
	Contact contacts[8];
	int 	index;

public:
	Phonebook() {
		index = 0;
	}
	void addContact(Contact c) {
		contacts[index] = c;
		index++;
		if (index > 7)
			index = 0;
	}
	void displayContacts() const {
		for(int i = 0; i < 8; i++)
			std::cout<<contacts[i].getFirstName()<<" | "
			<<contacts[i].getLastName()<< " | "<<
			contacts[i].getPhoneNum() << "\n";		
	}
};

int main()
{
	Phonebook book;
	std::string cmd;
	std::string input;

	while(cmd != "EXIT")
	{
		std::cout << "***********************\n";
		std::cout << "* ADD | SEARCH | EXIT *\n";
		std::cout << "***********************\n";
		std::cin >> cmd;
		if(cmd == "ADD")
		{
			Contact c;
			std::cout << "Enter First Name ------: ";
			std::cin >> input;
			c.setFirstName(input);
			std::cout << "Enter Last Name -------: ";
			std::cin >> input;
			c.setLastName(input);
			std::cout << "Enter Nickname --------: ";
			std::cin >> input;
			c.setNickName(input);
			std::cout << "Enter Phone number ----: ";
			std::cin >> input;
			c.setPhoneNum(input);
			std::cout << "Enter Darkest Secret --: ";
			std::cin >> input;
			c.setDarkSecret(input);
			book.addContact(c);
		}
		if(cmd == "SEARCH")
		{
			book.displayContacts();
		}
	}
}