#include "thorium.h"

#include <exception>
#include <string.h>
#include <fcgi_stdio.h>

Thorium::Thorium(void) {
    thorium_root = env.getExecutableDir();
}

Thorium::~Thorium(void) {
}

int Thorium::initialize(void) {
    return 0;
}

int Thorium::run(void) {
    printf("Content-Type: text/html; charset=UTF-8\r\n\r\n");
    auto map = env.getAll();
    for (auto i = map.begin(); i != map.end(); i++) {
        auto key = i->first;
        auto value = i->second;
        printf("<p>%s: %s</p>", key.c_str(), value.c_str());
    }
    printf("<p>%s</p>", thorium_root.c_str());
    return 0;
}

int Thorium::finalize(void) {
    env.resetMap();
    return 0;
}
