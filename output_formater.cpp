#include "output_formater.hpp"
#include "program_options.hpp"


void output_formated(std::string line, int index, int pattern_size){

    int line_size = line.size();
    int i;
    for(i = 0; i < index; i++){

        std::cout << line[i];

    }
    try
    {
        std::string color_code = get_color_code();
        std::cout << color_code << std::ends;
    }
    catch(const std::exception& e)
    {
        std::cerr << "void output_formated(std::string line, int index, int pattern_size)" << e.what() << '\n';
    }
    
    for(i=i;i < index + pattern_size; i++){
        std::cout << line[i];
    }

    std::cout << "\033[0m";

    for(i=i; i < line_size; i++){
        std::cout << line[i];
    }
    std::cout<<std::endl;

}