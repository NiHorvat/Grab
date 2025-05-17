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
    bool no_line_number = false;

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
void _get_no_line_number(std::vector<std::string> tokens){

    for(const auto &token : tokens){
        if(token == "-nl" || token == "--no-line-number"){
            p_options.no_line_number = true;
            break;
        }
    }


}

void _print_help(){
    std::cout << "This is the help page for GRAB tool" << std::endl;
    std::cout << "What is the GRAB tool : it is a copy of grep, with less features but created souly by His Majesty Nikola Horvat\n" << std::endl;
    std::cout << "How to use this tool?" << std::endl;
    std::cout << "USE PATERN:\n    ./grab {pattern} {filename} {flag_1} {value_1} {flag_2}...\n" << std::endl;        
    std::cout << "replace things in {} with the actual information\n\n\n" << std::endl;

    std::cout << "SUPPORTED FLAGS\n" << std::endl;
    std::cout << std::setw(20) << " -c/--color {color_name}" << std::setw(100) << "supported colors : black,red,green,yellow,blue,magenta,cyan,white" << std::endl;
    std::cout << std::setw(20) << " -nl/--no-line-numbers" << std::setw(100) << "bool flag indicating a want for no line numbers in output, default false" << std::endl;


}



//this function overflows everything 
//and then exits the program, bc if you call help ykikyk
void _get_help(std::vector<std::string> tokens){

    if(tokens[0] == "-h" || tokens[0] == "--help"){
        _print_help();
        exit(0);
    }

}




void parse_options(int argc, char *argv[]){

    std::vector<std::string> tokens(argv + 1, argv + argc);
    _get_help(tokens);
    _get_expresion(tokens);
    _get_filename(tokens);
    _get_color(tokens);
    _get_no_line_number(tokens);

    
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

bool get_no_line_number(){
    return p_options.no_line_number;
}

