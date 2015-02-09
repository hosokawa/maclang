#include "string.h"
#include <map>

#include <stdlib.h>

namespace cgi {
    class Environment {
        std::map<cgi::string, cgi::string>* all;
        cgi::string* executable_path;
        cgi::string* executable_dir;

    public:
        Environment(void);
        virtual ~Environment(void);

        char *c_getenv(const char *name) { return ::getenv(name); }
        cgi::string getenv(const char *name) { return ::getenv(name); }

        std::map<cgi::string, cgi::string>& getAll();

        void resetMap(void);
        cgi::string& getExecutablePath(void);
        cgi::string& getExecutableDir(void);
    };
}
