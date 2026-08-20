#ifndef APICLIENT_H
#define APICLIENT_H

#include <string>
#include <curl/curl.h>

class APIClient {
public:
    APIClient();
    ~APIClient();
    
    // Fetch data from a URL and return response as string
    std::string fetch(const std::string& url);
    
private:
    // Static callback for libcurl (must be static to work with C API)
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* s);
};

#endif // APICLIENT_H
