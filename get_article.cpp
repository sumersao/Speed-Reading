#include <string>
#include <curl/curl.h>
#include <cstdlib>

struct memory {
    char *memory;
    size_t size;
};

static size_t callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    memory *mem = (memory *) userp;

    char *ptr = (char *) realloc(mem->memory, mem->size + realsize + 1);

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}


std::string get_article(const std::string &url) {
    CURL *curl = curl_easy_init(); 
    std::string result;
    memory data;
    data.memory = (char *) malloc(1);
    data.size = 0;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, ("http://localhost:3000/article?url=" + url).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &data);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            throw "curl failed";
        }
        curl_easy_cleanup(curl);
        result.append(data.memory);
        free(data.memory);
        return result;
    } else throw "error reading article";
}





















