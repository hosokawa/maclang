#include "environment.h"

#include <string.h>
extern char **environ;

cgi::Environment::Environment(void) {
    all = nullptr;
}

cgi::Environment::~Environment(void) {
    resetMap();
}

std::map<std::string, std::string>& cgi::Environment::getAll() {
    if (all == nullptr) {
        all = new std::map<std::string, std::string>();
        for (int i = 0; environ[i]; i++) {
            for (int j = 0; environ[i][j]; j++) {
                if (environ[i][j] == '=') {
                    all->insert(std::map<std::string, std::string>::value_type(std::string(environ[i], j), std::string(environ[i] + j + 1)));
                }
            }
        }
    }
    return *all;
}

void cgi::Environment::resetMap(void) {
    if (all != nullptr) {
        delete all;
        all = nullptr;
    }
}
