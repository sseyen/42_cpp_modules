#include "PhoneBook.hpp"
#include <iomanip>

static std::string formatField(const std::string& field) {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

PhoneBook::PhoneBook() : _contactCount(0), _index(-1) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact& contact) {
	_index = (_index + 1) % 8;
	_contacts[_index] = contact;
	_contactCount++;
	if (_contactCount > 8)
		_contactCount = 8;
}

Contact	PhoneBook::getContact(int index) const {
	if (index < 0 || index >= 8) {
		return Contact();
	}
	return _contacts[index];
}

int	PhoneBook::getContactCount() const {
	return _contactCount;
}

void	PhoneBook::displayContacts() const {
	if (_contactCount == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _contactCount; i++) {
		const Contact& contact = _contacts[i];
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(contact.getFirstName()) << "|"
				  << std::setw(10) << formatField(contact.getLastName()) << "|"
				  << std::setw(10) << formatField(contact.getNickname()) << std::endl;
	}
}
