#include "Contact.hpp"

Contact::Contact() {
	this->name = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkSecret = "";
}

Contact::Contact(std::string name, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkSecret) {
	this->name = name;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkSecret = darkSecret;
}

Contact::~Contact() {}

std::string	Contact::getName(bool truncate) {
	return truncate ? this->truncate(this->name) : this->name;
}

std::string	Contact::getLastName(bool truncate) {
	return truncate ? this->truncate(this->lastName) : this->lastName;
}

std::string	Contact::getNickName(bool truncate) {
	return truncate ? this->truncate(this->nickName) : this->nickName;
}

std::string	Contact::getPhoneNumber(bool truncate) {
	return truncate ? this->truncate(this->phoneNumber) : this->phoneNumber;
}

std::string	Contact::getDarkSecret(bool truncate) {
	return truncate ? this->truncate(this->darkSecret) : this->darkSecret;
}

std::string	Contact::truncate(std::string str) {
	std::string	aux;

	if(str.length() <= 10)
		return (str);
	for(int i = 0; i < 9; i++)
		aux += str[i];
	aux += '.';
	return (aux);
}

