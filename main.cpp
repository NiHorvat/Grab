#include <iostream>
#include <vector>
#include "algos.h"
#include "buffer.h"
#include "algos.h"
#include "output_formater.h"

#define INTMAX  2147483647


int main(void){

    std::string filename = "hamlet.txt";
    size_t buffer_size = 1024;
    init_buffer(filename,buffer_size);

    std::string pattern = "fame";
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