#include <iostream>
#include <sstream>
#include <cstdlib>
#include "PhoneBook.hpp"

static std::string readField(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            std::exit(0);
        }
        if (!input.empty())
            return input;
    }
}

Contact getContact() {
    Contact contact;

    contact.setFirstName(readField("Enter First Name: "));
    contact.setLastName(readField("Enter Last Name: "));
    contact.setNickname(readField("Enter Nickname: "));
    contact.setPhoneNumber(readField("Enter Phone Number: "));
    contact.setDarkestSecret(readField("Enter Darkest Secret: "));

    return contact;
}

int searchContact(const PhoneBook& phoneBook) {
    std::string input;
    int         index;

    if (phoneBook.getContactCount() == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return -1;
    }
    
    phoneBook.displayContacts();
    std::cout << "Enter the index of the contact to view details: ";
    
    if (!std::getline(std::cin, input)) {
        std::cout << std::endl;
        return -1;
    }
    
    std::stringstream ss(input);
    if (!(ss >> index) || !(ss >> std::ws).eof() || index < 0 || index >= phoneBook.getContactCount()) {
        std::cout << "Invalid index." << std::endl;
        return -1;
    }

    return index;
}

int main(void) {
    PhoneBook   phoneBook;
    Contact     contact;
    std::string command;
    int         index;

    std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
    
    while (std::getline(std::cin, command)) {
        if (command == "EXIT") {
            break;
        }
        else if (command == "ADD") {
            contact = getContact();
            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH") {
            index = searchContact(phoneBook);
            if (index != -1)
                phoneBook.getContact(index).displayContact();
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }

        std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
    }
    
    if (std::cin.eof()) {
        std::cout << std::endl;
    }
    
    return 0;
}