#include "include/CLI.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

CLI::CLI(const std::map<std::string, std::string>& countryList): countrylist(countryList) {};

CLI::~CLI() {
}

void CLI::printmenu() {
    // so far exit first for convenience in development might change later
    // but dont want to shift it down each feature I make
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Exit" << std::endl;
    std::cout << "2. Browse country list" << std::endl;
    
}

void CLI::browseCountryList() {
    std::string filter;
    std::cout << "Enter a first letter or 'all': ";
    std::cin >> filter;

    std::transform(filter.begin(), filter.end(), filter.begin(), [](unsigned char character) {
        return static_cast<char>(std::tolower(character));
    });

    if (filter != "all" &&
        (filter.size() != 1 || !std::isalpha(static_cast<unsigned char>(filter[0])))) {
        std::cout << "Please enter one letter or 'all'." << std::endl;
        return;
    }

    std::vector<std::pair<std::string, std::string>> matches;
    for (const auto& country : countrylist) {
        if (filter == "all" ||
            std::tolower(static_cast<unsigned char>(country.first[0])) ==
                std::tolower(static_cast<unsigned char>(filter[0]))) {
            matches.push_back(country);
        }
    }

    if (matches.empty()) {
        std::cout << "No countries found." << std::endl;
        return;
    }

    constexpr std::size_t pageSize = 10;
    std::size_t pageStart = 0;

    while (pageStart < matches.size()) {
        const std::size_t pageEnd =
            std::min(pageStart + pageSize, matches.size());

        std::cout << "\nCountries " << pageStart + 1 << "-" << pageEnd
                  << " of " << matches.size() << ":" << std::endl;
        for (std::size_t index = pageStart; index < pageEnd; ++index) {
            std::cout << "Country: " << matches[index].first
                      << ", Code: " << matches[index].second << std::endl;
        }

        pageStart = pageEnd;
        if (pageStart < matches.size()) {
            std::cout << "Enter 'n' for next page or 'q' to return: ";
            char command;
            std::cin >> command;
            if (command != 'n' && command != 'N') {
                break;
            }
        }
    }
}