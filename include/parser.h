#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>

class Parser {
public:
    // Parse the JSON response from the World Bank API to format country codes and names
    std::map<std::string, std::string> country(const std::string& jsonResponse);
};



#endif // PARSER_H
