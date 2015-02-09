#include "environment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libproc.h>
#include <unistd.h>

extern char **environ;

cgi::Environment::Environment(void)
  : all(nullptr)
  , executable_path(nullptr)
  , executable_dir(nullptr) {
}

cgi::Environment::~Environment(void) {
    resetMap();
    if (executable_path != nullptr) {
        delete executable_path;
        executable_path = nullptr;
    }
    if (executable_dir != nullptr) {
        delete executable_dir;
        executable_dir = nullptr;
    }
}

std::map<cgi::string, cgi::string>& cgi::Environment::getAll() {
    if (all == nullptr) {
        all = new std::map<cgi::string, cgi::string>();
        for (int i = 0; environ[i]; i++) {
            for (int j = 0; environ[i][j]; j++) {
                if (environ[i][j] == '=') {
                    all->insert(std::map<cgi::string, cgi::string>::value_type(cgi::string(environ[i], j), cgi::string(environ[i] + j + 1)));
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

cgi::string& cgi::Environment::getExecutablePath(void) {
    if (executable_path == nullptr) {
        pid_t pid; int ret;
        char pathbuf[PROC_PIDPATHINFO_MAXSIZE];

        pid = getpid();
        ret = proc_pidpath(pid, pathbuf, sizeof(pathbuf));
        if (ret <= 0) {
            throw new std::exception();
        } else {
            executable_path = new cgi::string(pathbuf);
        }
    }
    return *executable_path;
}

cgi::string& cgi::Environment::getExecutableDir(void) {
    if (executable_dir == nullptr) {
        cgi::string& path = getExecutablePath();
        size_t pos = path.find_last_of('/');
        if (pos != cgi::string::npos) {
            executable_dir = new cgi::string(path, 0, pos);
        } else {
            throw new std::exception();
        }
    }
    return *executable_dir;
}
