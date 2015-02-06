#include "classes/thorium.h"

#include <fcgi_stdio.h>

int main(int argc, char *argv[]) {
    Thorium thorium;
    while (FCGI_Accept() >= 0)   {
        thorium.initialize();
        thorium.run();
        thorium.finalize();
    }
}
