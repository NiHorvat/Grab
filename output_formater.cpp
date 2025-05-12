#include <iostream>
#include <vector>


void output_formated(std::string line, int index, int pattern_size){

    int line_size = line.size();
    int i;
    for(i = 0; i < index; i++){

        std::cout << line[i];

    }

    std::cout <<  "\033[1;31m";

    for(i=i;i < index + pattern_size; i++){
        std::cout << line[i];
    }

    std::cout << "\033[0m";

    for(i=i; i < line_size; i++){
        std::cout << line[i];
    }
    std::cout<<std::endl;

}