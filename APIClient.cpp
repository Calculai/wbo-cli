#include "include/APIClient.h"
#include <iostream>
#include <stdexcept>

APIClient::APIClient() {
    // Constructor - could initialize curl globally if needed
}

APIClient::~APIClient() {
    // Destructor - cleanup if needed
}

// Static callback for libcurl
size_t APIClient::writeCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Fetch data from URL
std::string APIClient::fetch(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to fetch data: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
    }
    
    return readBuffer;
}

// Fetch and parse a JSON response
nlohmann::json APIClient::fetchJson(const std::string& url) {
    const std::string response = fetch(url);

    if (response.empty()) {
        throw std::runtime_error("API returned an empty response");
    }

    try {
        return nlohmann::json::parse(response);
    } catch (const nlohmann::json::parse_error& error) {
        throw std::runtime_error(
            std::string("Failed to parse API response as JSON: ") + error.what());
    }
}
