#include "program_options.hpp"

const std::string ANSI_COLOR_BLACK = "\x1b[30m";
const std::string ANSI_COLOR_RED = "\x1b[31m";
const std::string ANSI_COLOR_GREEN = "\x1b[32m";
const std::string ANSI_COLOR_YELLOW = "\x1b[33m";
const std::string ANSI_COLOR_BLUE = "\x1b[34m";
const std::string ANSI_COLOR_MAGENTA = "\x1b[35m";
const std::string ANSI_COLOR_CYAN = "\x1b[36m";
const std::string ANSI_COLOR_WHITE = "\x1b[37m";

const std::string ANSI_BOLD = "\x1b[1m";
const std::string ANSI_UNDERLINE = "\x1b[4m";
const std::string ANSI_RESET = "\x1b[0m";

struct
{
    std::string expresion = "";
    std::string filename = "";
    std::string color_code = "";
    bool no_line_number = false;

} typedef program_options;

program_options p_options;

std::string _switch_colors(std::string color)
{

    if (color == "black")
        return ANSI_COLOR_BLACK;
    if (color == "red")
        return ANSI_COLOR_RED;
    if (color == "green")
        return ANSI_COLOR_GREEN;
    if (color == "yellow")
        return ANSI_COLOR_YELLOW;
    if (color == "blue")
        return ANSI_COLOR_BLUE;
    if (color == "magenta")
        return ANSI_COLOR_MAGENTA;
    if (color == "cyan")
        return ANSI_COLOR_CYAN;
    if (color == "white")
        return ANSI_COLOR_WHITE;
    return "";
}

void _get_color(std::vector<std::string> tokens)
{

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "--color" || tokens[i] == "-c")
        {
            if (i + 1 < tokens.size())
            {
                p_options.color_code = _switch_colors(tokens[i + 1]);
                break;
            }
        }
    }
}

void _get_filename(std::vector<std::string> tokens)
{

    try
    {
        p_options.filename = tokens[1];
        if (p_options.filename == "")
            throw std::runtime_error("filename == \"\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << "void _get_filename(std::vector<std::string> tokens)" << e.what() << '\n';
        exit(0);
    }
}

void _get_expresion(std::vector<std::string> tokens)
{

    try
    {
        p_options.expresion = tokens[0];
        if (p_options.expresion == "")
            throw std::runtime_error("pattern == \"\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << "void _get_expresion(std::vector<std::string> tokens)" << e.what() << '\n';
        exit(0);
    }
}
void _get_no_line_number(std::vector<std::string> tokens)
{

    for (const auto &token : tokens)
    {
        if (token == "-nl" || token == "--no-line-number")
        {
            p_options.no_line_number = true;
            break;
        }
    }
}

void _print_help()
{
    std::cout << "\n"
              << ANSI_BOLD << ANSI_COLOR_CYAN << "GRAB TOOL HELP" << ANSI_RESET << "\n"
              << std::endl;

    std::cout << ANSI_BOLD << "Description:" << ANSI_RESET << std::endl;
    std::cout << "  A grep-like tool created by " << ANSI_BOLD << "Nikola Horvat" << ANSI_RESET << std::endl;
    std::cout << "  Simplified version with essential functionality\n"
              << std::endl;

    std::cout << ANSI_BOLD << "Usage Pattern:" << ANSI_RESET << std::endl;
    std::cout << "  " << ANSI_COLOR_GREEN << "./grab {pattern} {filename} [options]" << ANSI_RESET << "\n"
              << std::endl;

    std::cout << ANSI_BOLD << "Options:" << ANSI_RESET << std::endl;
    std::cout << ANSI_BOLD << "  -c, --color <color>" << ANSI_RESET << std::endl;
    std::cout << "      Highlight matches with specified color" << std::endl;
    std::cout << "      Available colors: ";
    std::cout << ANSI_COLOR_BLACK << "black" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_RED << "red" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_GREEN << "green" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_YELLOW << "yellow" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_BLUE << "blue" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_MAGENTA << "magenta" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_CYAN << "cyan" << ANSI_RESET << ", ";
    std::cout << ANSI_COLOR_WHITE << "white" << ANSI_RESET << "\n"
              << std::endl;

    std::cout << ANSI_BOLD << "  -nl, --no-line-numbers" << ANSI_RESET << std::endl;
    std::cout << "      Disable line numbers in output (default: enabled)\n"
              << std::endl;

    std::cout << ANSI_BOLD << "Examples:" << ANSI_RESET << std::endl;
    std::cout << "  " << ANSI_COLOR_YELLOW << "./grab \"search_term\" file.txt --color red" << ANSI_RESET << std::endl;
    std::cout << "  " << ANSI_COLOR_YELLOW << "./grab \"pattern\" data.log -c blue --no-line-numbers" << ANSI_RESET << std::endl;
    std::cout << "  " << ANSI_COLOR_YELLOW << "./grab \"error\" log.txt | less -R" << ANSI_RESET << " (for paging with color)" << std::endl;
}

// this function overflows everything
// and then exits the program, bc if you call help ykikyk
void _get_help(std::vector<std::string> tokens)
{

    try
    {
        if (tokens[0] == "-h" || tokens[0] == "--help")
        {
            _print_help();
            exit(0);
        }
        if(tokens[0] == "") throw std::runtime_error("tokens[0] == \"\"");
    }
    catch (const std::exception &e)
    {
        std::cerr << "void _get_help(std::vector<std::string> tokens)" << e.what() << '\n';
        exit(0);
    }
}

void parse_options(int argc, char *argv[])
{

    std::vector<std::string> tokens;

    try
    {
        tokens.assign(argv + 1, argv + argc);
        if(tokens.size() == 0) throw std::runtime_error("tokens.size() == 0");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "void parse_options(int argc, char *argv[]) " << e.what() << '\n';
        exit(0);
    }
    

    _get_help(tokens);
    _get_expresion(tokens);
    _get_filename(tokens);
    _get_color(tokens);
    _get_no_line_number(tokens);

}

std::string get_color_code()
{
    return p_options.color_code;
}

std::string get_expresion()
{
    return p_options.expresion;
}

std::string get_filename()
{
    return p_options.filename;
}

bool get_no_line_number()
{
    return p_options.no_line_number;
}
