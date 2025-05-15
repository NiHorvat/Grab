#include <iostream>
#include <vector>
#include <string_view>
#include "output_formater.hpp"
#include "algos.hpp"
#include "buffer.hpp"
#include "algos.hpp"
#include "program_options.hpp"



int main(int argc, char* argv[]){

    parse_options(argc,argv);


    std::string filename = "hamlet.txt";
    size_t buffer_size = 1024;
    init_buffer(filename,buffer_size);

    std::string pattern = "audio";
    int pattern_size = pattern.size();
    init_algos(pattern);

    std::string line;
    int index = -1;
    while(get_next_line(line)){
        index = check_line(line);
        if(index > 0){
            output_formated(line,index,pattern_size);       
        }

    }


    return 0;

}