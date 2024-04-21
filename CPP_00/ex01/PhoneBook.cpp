#include "apb.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

static bool	isFullSpaces(std::string& input) {
	for (int i = 0; input[i]; i++) {
		if (!std::isspace(input[i]))
			return false;
	}
	return true;
}

static bool	isValidNumber(std::string& input) {
	if (input.length() != 9) {
		std::cout << RED << "Number must have 9 digits." << RESET << std::endl;
		return false;
	}
	for (int i = 0; input[i]; i++) {
		if (!std::isdigit(input[i])) {
			std::cout << RED << "Number can only contain numbers." << RESET << std::endl;
			return false;
		}
	}
	return true;
}

static std::string	askInfo(std::string question) {
	std::string	input;

	while (input.empty() || isFullSpaces(input)) {
		std::cout << question;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << RED << "\nCtrl + D signal. Exiting..." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (input.empty() || isFullSpaces(input)) {
			std::cout << RED << "Input cannot be empty." << RESET << std::endl;
			continue ;
		}
		if ((question.compare("Phone number: ") == 0) && !isValidNumber(input)) {
			input.clear();
	continue ;
		}
	}
	for (int i = 0; input[i]; i++) {
		if (input[i] == '\t')
			input.replace(i, 1, " ");
	}
	return (input);
}

static bool	isValidIndex(std::string index) {
	if (index.length() != 1) {
		std::cout << RED << "Invalid index. Please type only one digit." << RESET << std::endl;
		return false;
	}
	if (!std::isdigit(index.at(0)) || index.at(0) > '8') {
		std::cout << RED << "Index needs to be a number from 0 to 8." << RESET << std::endl;
		return false;
	}
	return true;
}

/* Constructor */
PhoneBook::PhoneBook() {
	this->position = 0;
	this->isFull = false;
}

/* Destructor */
PhoneBook::~PhoneBook() {}

/* get total contacts */
size_t	PhoneBook::getTotal() {
	return this->isFull ? MAX_CONTACTS : this->position;
}

/* add Contact */
void	PhoneBook::add() {
	std::string	name, lastName, nickName, phoneNumber, darkSecret;

	std::cout << "Please fill in the details of the new contact:" << std::endl;
	name = askInfo("First Name: ");
	lastName = askInfo("Last Name: ");
	nickName = askInfo("Nick Name: ");
	phoneNumber = askInfo("Phone number: ");
	darkSecret = askInfo("Dark Secret: ");

	if (this->position == MAX_CONTACTS)
	{
		this->isFull = true;
		this->position = 0;
	}
	this->contacts[position] = Contact(name, lastName, nickName, phoneNumber, darkSecret);
	this->position++;
	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
}

/* seach contact */
void	PhoneBook::search() {
	size_t 		curr_index;
	std::string	index;

	curr_index = this->getTotal();
	if (curr_index == 0 && !this->isFull) {
		std::cout << "Contact list is empty! Add a new contact before checking the list." << std::endl;
		return ;
	}
	std::cout << "|" << std::setfill(' ') << std::setw(11) << "Index|";
	std::cout << std::setfill(' ') << std::setw(11) << "First Name|";
	std::cout << std::setfill(' ') << std::setw(11) << "Last Name|";
	std::cout << std::setfill(' ') << std::setw(11) << "Nickname|" << std::endl;

	for(size_t i = 0; i < curr_index; i++) {
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getName(true) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getLastName(true) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getNickName(true) << "|";
		std::cout << std::endl;
	}

	std::cout  << std::endl;
	while (1) {
		std::cout << "Type an index to see in detail or 0 to return to menu: ";
		std::getline(std::cin, index);
		if (std::cin.eof()) {
			std::cout << RED << "\nCtrl + D signal. Exiting..." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		if (index.compare("0") == 0)
			break ;
		else if (isValidIndex(index)) {
			if (!this->isFull && ((index[0] - '1') > ((int)this->position - 1))) {
				std::cout << RED << "There is no contact for that index." << RESET << std::endl;
				continue ;
			}
			std::cout << CYAN << "CONTACT INFO:" << RESET << std::endl;
			std::cout << "First Name: " << this->contacts[index[0] - '1'].getName(false) << std::endl;
			std::cout << "Last Name: " << this->contacts[index[0] - '1'].getLastName(false) << std::endl;
			std::cout << "Nick Name: " << this->contacts[index[0] - '1'].getNickName(false) << std::endl;
			std::cout << "Phone Number: " << this->contacts[index[0] - '1'].getPhoneNumber(false) << std::endl;
			std::cout << "Darkest Secret: " << this->contacts[index[0] - '1'].getDarkSecret(false) << std::endl;
		}
	}
}
