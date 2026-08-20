#include <iostream>
#include <string>
#include "APIClient.h"

int main() {
    std::cout << "Fetching countries from World Bank API..." << std::endl;
    
    APIClient client;
    std::string response = client.fetch("https://api.worldbank.org/v2/country?format=json");
    
    std::cout << "Response (first 500 chars):\n" << response.substr(0, 500) << std::endl;
    
    return 0;
}
