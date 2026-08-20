#ifndef CLI_H
#define CLI_H

#include <string>
#include <map>

class CLI {
public:
    CLI(const std::map<std::string, std::string>& countryList): countrylist(countryList) {};
    ~CLI();

    // Prints all countries and their countrycode
    void printCoulist(); 

private:
    std::map<std::string, std::string> countrylist;
};

#endif // CLI_H
