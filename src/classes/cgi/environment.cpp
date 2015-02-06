#include "environment.h"

#include <string.h>
extern char **environ;

cgi::Environment::Environment(void) {
    this->all = nullptr;
}

cgi::Environment::~Environment(void) {
    if (this->all != nullptr) {
        delete this->all;
        this->all = nullptr;
    }
}

std::map<std::string, std::string>& cgi::Environment::getAll() {
    if (this->all == nullptr) {
        this->all = new std::map<std::string, std::string>();
        for (int i = 0; environ[i]; i++) {
            for (int j = 0; environ[i][j]; j++) {
                if (environ[i][j] == '=') {
                    this->all->insert(std::map<std::string, std::string>::value_type(std::string(environ[i], j), std::string(environ[i] + j + 1)));
                }
            }
        }
    }
    return *this->all;
}
