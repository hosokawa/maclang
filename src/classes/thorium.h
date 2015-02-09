#include "cgi/environment.h"

class Thorium {
    cgi::Environment env;
    std::string thorium_root;

public:
    Thorium(void);
    ~Thorium(void);

public:
    int initialize(void);
    int run(void);
    int finalize(void);
};
