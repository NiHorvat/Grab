#include <iostream>
#include <vector>
#include <string_view>
#include "output_formater.hpp"
#include "algos.hpp"
#include "buffer.hpp"
#include "algos.hpp"
#include "program_options.hpp"

int main(int argc, char *argv[])
{

    parse_options(argc, argv);

    std::string pattern = get_expresion();
    int pattern_size = pattern.size();
    init_algos(pattern);

    std::vector<std::string> filenames = get_filenames();
    size_t buffer_size = 1024;
    for (const auto &filename : filenames)
    {

        std::cout << "\n----------------------------------------" << std::endl;
        std::cout << "FILENAME : " << filename << std::endl;
        std::cout << "PATTERN  : " << pattern << std::endl;
        std::cout << "----------------------------------------\n\n" << std::endl;

        init_buffer(filename, buffer_size);

        const auto output = check_file();

        for (const auto &el : output)
        {
            if (!get_no_line_number())
            {
                std::cout << el.first << "          ";
            }
            output_formated(el.second.second, el.second.first, pattern_size);
        }


    }

    return 0;
}