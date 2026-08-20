#include <iostream>
#include <string>
#include <map>
#include "include/APIClient.h"
#include "include/parser.h"


int main() {
    // Initialization, fetch country names
    std::map<std::string, std::string> countrylist;
    std::cout << "Fetching countries from World Bank API..." << std::endl;

    APIClient client;
    std::string response = client.fetch("https://api.worldbank.org/v2/country?format=json");
    
    Parser parser;
    std::map<std::string, std::string> countrylist = parser.country(response);
    
    return 0;
}
