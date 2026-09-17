#include "include/parser.h"

std::map<std::string, std::string>
Parser::country(const nlohmann::json& jsonResponse) {
	std::map<std::string, std::string> countries;

	for (const auto& country : jsonResponse.at(1)) {
		countries[country.at("name").get<std::string>()] =
			country.at("iso2Code").get<std::string>();
	}

	return countries;
}
