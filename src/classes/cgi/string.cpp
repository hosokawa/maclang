#include "string.h"

cgi::string& cgi::string::escape_html() {
    cgi::string buffer;
    buffer.reserve(size() * 2);
    for (const char *p = c_str(); *p; p++) {
        switch (*p) {
        case '&':
            buffer.append("&amp;");
            break;
        case '\"':
            buffer.append("&quot;");
            break;
        case '\'':
            buffer.append("&apos;");
            break;
        case '<':
            buffer.append("&lt;");
            break;
        case '>':
            buffer.append("&gt;");
            break;
        default:
            buffer.append(p, 1);
            break;
        }
    }
    return *this;
}
