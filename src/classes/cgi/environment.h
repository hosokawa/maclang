#include <string>
#include <map>

#include <stdlib.h>

namespace cgi {
    class Environment {
        std::map<std::string, std::string>* all;

    public:
        Environment(void);
        virtual ~Environment(void);

        char *c_getenv(const char *name) { return ::getenv(name); }
        std::string getenv(const char *name) { return ::getenv(name); }

        std::map<std::string, std::string>& getAll();

        void resetMap(void);
    };
}
