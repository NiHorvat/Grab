#include "program_options.hpp"

std::vector<std::string> arguments;

struct options
{
    std::string color_code = "";
    
};

options *opt;



void parse_options(int argc, char *argv[]){
    arguments.assign(argv + 1, argv + argc);
    get__all_options();

}


void get__all_options(){
    get_color();
}


void get_color(){

    std::cout << "lele" << std::endl;
    for(size_t i = 0; i < arguments.size(); i++){
        if(arguments[i] == "-c" || arguments[i] == "--color"){
            
            if(!opt->color_code.empty()){
                throw std::runtime_error("can't specify -c/--color more than once");
            }
            if(i+1 < arguments.size()){
                opt->color_code = arguments[i+1];
                return;
            }
        }
    }
}




std::string get_color_code(){

    return opt->color_code;

}



