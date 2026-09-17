#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>
#include <nlohmann/json.hpp>

class Parser {
public:
    // Parse country names and codes from a World Bank JSON response
    std::map<std::string, std::string> country(const nlohmann::json& jsonResponse);
};



#endif // PARSER_H
