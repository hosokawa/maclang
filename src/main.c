#include "fcgi_stdio.h"
#include <stdlib.h>

int count;

void initialize(void) {
    count = 0;
}

int main(int argc, char *argv[]) {
    initialize();
    while (FCGI_Accept() >= 0)   {
        printf(
            "Content-type: text/html\r\n"
            "\r\n"
            "<title>FastCGI Hello! (C, fcgi_stdio library)</title>"
            "<h1>FastCGI Hello! (C, fcgi_stdio library)</h1>"
            "Request number %d running on host <i>%s</i>\n",
            ++count,
            getenv("SERVER_NAME")
        );
    }
}
