#include "include/CLI.h"
#include <iostream>

CLI::CLI(const std::map<std::string, std::string>& countryList): countrylist(countryList) {};

CLI::~CLI() {
    // Destructor implementation (if needed)
}


void CLI::printCoulist() {

    std::cout << "Country List:" << std::endl;

    for (const auto& pair : countrylist) {
        std::cout << "Country: " << pair.first << ", Code: " << pair.second << std::endl;
    }
}