#include <string_view>
#include <vector>
#include <filesystem>
#include <stdexcept>

namespace program_options {

void parse(int argc, char* argv[]);

const std::vector<std::string_view>& input_files();
bool                                 show_ends();
bool                                 show_line_numbers();

};  // namespace program_options