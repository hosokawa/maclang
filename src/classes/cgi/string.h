#include <string>

namespace cgi {
    class string : public std::string {
    public:
        string() : std::string() {}
        string(const char *str) : std::string(str) {}
        string(const char *str, size_t len) : std::string(str, len) {}
        string(const std::string &s) : std::string(s) {}
        string(const std::string &s, size_t start, size_t len) : std::string(s, start, len) {}
        string& operator=(const char *str) {
            std::string::operator=(str);
            return *this;
        }
        string& operator=(const std::string& s) {
            std::string::operator=(s);
            return *this;
        }

    public:
        string& escape_html();
    };
}
