/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmcgrane <jmcgrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:04:54 by jmcgrane          #+#    #+#             */
/*   Updated: 2026/03/19 15:57:34 by jmcgrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
	int 	index = 0;

public:
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
	bool isvalid;
	Phonebook book;
	std::string cmd;
	std::string input;

	while(cmd != "EXIT")
	{
		std::cout << "***********************\n";
		std::cout << "* ADD | SEARCH | EXIT *\n";
		std::cout << "***********************\n";
		std::getline(std::cin, cmd);
		if(cmd == "ADD")
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
			book.addContact(c);
			contact_successfull();
		}
		if(cmd == "SEARCH")
		{
			book.displayContacts();
		}
	}
}
