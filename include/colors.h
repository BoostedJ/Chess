#ifndef COLORS_H
#define COLORS_H
#include <string>

const std::string RESET = "\033[0m";
const std::string WHITE = "\033[0m";
const std::string BLACK = "\033[90m";

inline std::string colorText(const std::string& text, const std::string& color) {
    return color + text + RESET;
}

#endif //COLORS_H
