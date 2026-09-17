#ifndef CLI_H
#define CLI_H

#include <string>
#include <map>

class CLI {
public:
    CLI(const std::map<std::string, std::string>& countryList);
    ~CLI();

    // Browses countries by first letter and in pages
    void browseCountryList();

    // Prints the main menu of the CLI
    void printmenu();

private:
    std::map<std::string, std::string> countrylist;
};

#endif // CLI_H
