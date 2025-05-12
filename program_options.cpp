#include "program_options.hpp"

namespace
{

    static std::vector<std::string_view> _input_files;
    static std::string_view _color_opening = "";
    static std::string_view _color_clossing = "";

} // namespace


//TODO nemam pojima
void program_options::parse(int argc, char *argv[])
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    for (const auto &arg : args)
    {
        if (_input_files.empty())
        {
           if(arg == "-c" || "--color"){
                if(!_color_opening.empty() || !_color_clossing.empty()){
                    throw std::runtime_error("cannot use -c/--color parametar twice");
                }
                //ovdje treba dodati neš
           }
        }

        if (!std::filesystem::exists(arg))
        {
            throw std::runtime_error(std::string("dog: ") + std::string(arg) + ": No such file or directory");
        }
        _input_files.push_back(arg);
    }
}

const std::vector<std::string_view> &
program_options::input_files()
{
    return _input_files;
}


std::string_view color_opening(){
    return _color_opening;
}

std::string_view color_closing(){
    return _color_clossing;
}


