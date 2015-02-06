#include <fcgi_stdio.h>
#include "classes/thorium.h"

int main(int argc, char *argv[]) {
    Thorium thorium;
    while (FCGI_Accept() >= 0)   {
        thorium.run();
    }
}
