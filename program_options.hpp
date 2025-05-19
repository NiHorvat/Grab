#include <string_view>
#include <vector>
#include <filesystem>
#include <stdexcept>
#include <iostream>

void parse_options(int argc, char *argv[]);

std::string get_expresion();
std::vector<std::string> get_filenames();
std::string get_color_code();
bool get_no_line_number();
