#include "program_options.hpp"

const std::string ANSI_COLOR_BLACK = "\x1b[30m";
const std::string ANSI_COLOR_RED = "\x1b[31m";
const std::string ANSI_COLOR_GREEN = "\x1b[32m";
const std::string ANSI_COLOR_YELLOW = "\x1b[33m";
const std::string ANSI_COLOR_BLUE = "\x1b[34m";
const std::string ANSI_COLOR_MAGENTA = "\x1b[35m";
const std::string ANSI_COLOR_CYAN = "\x1b[36m";
const std::string ANSI_COLOR_WHITE = "\x1b[37m";




struct 	
{
    std::string expresion = "";
    std::string filename = "";
    std::string color_code = "";

}typedef program_options;


program_options p_options;




std::string _switch_colors(std::string color){

    if(color == "black") return ANSI_COLOR_BLACK;
    if(color == "red") return ANSI_COLOR_RED;
    if(color == "green") return ANSI_COLOR_GREEN;
    if(color == "yellow") return ANSI_COLOR_YELLOW;
    if(color == "blue") return ANSI_COLOR_BLUE;
    if(color == "magenta") return ANSI_COLOR_MAGENTA;
    if(color == "cyan") return ANSI_COLOR_CYAN;
    if(color == "white") return ANSI_COLOR_WHITE;
    return "";
}


void  _get_color(std::vector<std::string> tokens){

    for(size_t i = 0; i < tokens.size(); i++){
        if(tokens[i] == "--color" || tokens[i] == "-c"){
            if(i + 1 < tokens.size()){
                p_options.color_code = _switch_colors(tokens[i+1]);
                break;
            }
        }
    }
}

void _get_filename(std::vector<std::string> tokens){

    p_options.filename = tokens[1]; 

}

void _get_expresion(std::vector<std::string> tokens){

    p_options.expresion = tokens[0]; 

}



void parse_options(int argc, char *argv[]){

    std::vector<std::string> tokens(argv + 1, argv + argc);
    _get_expresion(tokens);
    _get_filename(tokens);
    _get_color(tokens);

    
}



std::string get_color_code(){
    return p_options.color_code;
}


std::string get_expresion(){
    return p_options.expresion;
}

std::string get_filename(){
    return p_options.filename;
}



