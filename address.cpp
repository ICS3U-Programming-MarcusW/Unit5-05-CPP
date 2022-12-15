// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: December 6 2022
// This program asks the user for an address
// It then prints the address formatted.

#include <algorithm>
#include <iostream>

// Function to format the function
// Use a default value for the apartment number incase the user lives in an apt
std::string AddressFormatter(std::string name, std::string streetNumber,
                           std::string streetName, std::string city,
                           std::string province, std::string postalCode,
                           std::string aptNumber = "") {
    // Declare a variable for the final formatted address
    std::string mailingAddress;

    // Add the users name to the address
    mailingAddress += "\n" + name + "\n";

    // Checks if the user lives in an apartment
    if (aptNumber != "") {
        // Add the users apt number to the address
        mailingAddress += aptNumber + "-";
    }

    // Add the users street number, street name, city,
    // province and postal code to the mailing address
    mailingAddress += streetNumber + " " + streetName + "\n";
    mailingAddress += city + " " + province + " " + postalCode;

    // Converts the mailing address to uppercase
    // Taken from stack overflow (How to Convert a C++ String to Uppercase)
    std::transform(mailingAddress.begin(), mailingAddress.end(),
    mailingAddress.begin(), ::toupper);

    // Returns formatted address
    return mailingAddress;
}

int main() {
    // Declared variables (information in address)
    std::string userFullName, userApartment, userAptNumber, userStreetNum;
    std::string userStreetName, userCity, userProvince;
    std::string userPostalCode, userMailingAddress;

    // Get users name
    std::cout << "Enter your entire name: ";
    std::getline(std::cin, userFullName);

    // Asks user if they live inside an apartment
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, userApartment);

    // Converts user's apartment answer to uppercase
    std::transform(userApartment.begin(), userApartment.end(),
                   userApartment.begin(), ::toupper);

    // Get apt number if user lives in an apt
    if (userApartment == "Y") {
        // Asks user for their apartment number
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, userAptNumber);
    }

    // Get user postal code
    std::cout << "Enter your postal code: ";
    std::getline(std::cin, userPostalCode);

    // Get user street number
    std::cout << "Enter your street number: ";
    std::getline(std::cin, userStreetNum);

    // Get user street
    std::cout << "Enter your Street Name: ";
    std::getline(std::cin, userStreetName);

    // Get user city
    std::cout << "Enter your City Name: ";
    std::getline(std::cin, userCity);

    // Get user province
    std::cout << "Enter your province (first two letters): ";
    std::getline(std::cin, userProvince);

    // Call function to format address
    userMailingAddress = AddressFormatter(userFullName, userStreetNum,
    userStreetName, userCity, userProvince, userPostalCode, userAptNumber);

    // Displays formatted address to the user
    std::cout << "Your mailing address formatted: "
              << userMailingAddress << std::endl;
}
