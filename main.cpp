#include <iostream>
#include <string>
#include <map>
#include "include/APIClient.h"
#include "include/parser.h"
#include "include/CLI.h"


int main() {
    // Initialization, fetch country names
    std::cout << "Fetching countries from World Bank API..." << std::endl;

    APIClient client;
    nlohmann::json response =
        client.fetchJson("https://api.worldbank.org/v2/country?format=json&per_page=400");
    
    Parser parser;
    std::map<std::string, std::string> countrylist = parser.country(response);

    CLI cli(countrylist);
    bool running = true;

    while (running) {
        cli.printmenu();
        std::cout << "Choose an option: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a number." << std::endl;
            continue;
        }

        switch (choice) {
        case 1:
            running = false;
            break;
        case 2:
            cli.browseCountryList();
            break;
        default:
            std::cout << "Please choose a valid option." << std::endl;
            break;
        }
    }

    return 0;
}
