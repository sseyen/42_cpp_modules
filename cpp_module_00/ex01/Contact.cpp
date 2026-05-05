#include "Contact.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickname(""), _phoneNumber("") {}

Contact::~Contact() {}

void	Contact::displayContact() const {
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void	Contact::setFirstName(const std::string& firstName) {
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName) {
	_lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname) {
	_nickname = nickname;
}
void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const {
	return _firstName;
}

std::string	Contact::getLastName() const {
	return _lastName;
}

std::string	Contact::getNickname() const {
	return _nickname;
}

std::string	Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return _darkestSecret;
}
