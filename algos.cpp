
#include "buffer.hpp"

class Algos
{

private:
    std::string pattern;

    std::vector<int> rabin_karp(std::string line, int q)
    {

        std::vector<int> output;

        int M = this->pattern.size();
        int N = line.size();
        int i, j;
        int p = 0; 
        int t = 0; 
        int h = 1;
        int d = 256; 
        for (i = 0; i < M - 1; i++)
            h = (h * d) % q;


        for (i = 0; i < M; i++)
        {
            p = (d * p + this->pattern[i]) % q;
            t = (d * t + line[i]) % q;
        }

        for (i = 0; i <= N - M; i++)
        {


            if (p == t)
            {

                int flag = 1;
                for (j = 0; j < M; j++)
                {
                    if (line[i + j] != this->pattern[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    output.push_back(i);
                }
            }


            if (i < N - M)
            {
                t = (d * (t - line[i] * h) + line[i + M]) % q;


                if (t < 0)
                    t = (t + q);
            }
        }
        return output;
    }

public:

    Algos(std::string pattern){
        this->pattern = pattern;
    }

    std::vector<int> check_line(std::string line){
        return rabin_karp(line,INT32_MAX);
    }

};


Algos *alg = nullptr;


void init_algos(std::string pattern){

    try
    {
        alg = new Algos(pattern);
    }
    catch(const std::exception& e)
    {
        std::cerr << "void init_algos(std::string pattern)" << e.what() << '\n';
        exit(-1);
    }

}

std::vector<int> check_line(std::string line){

    try
    {
        return alg->check_line(line);
    }
    catch(const std::exception& e)
    {
        std::cerr << "int check_line(std::string line)" << e.what() << '\n';
        exit(-1);
    }
}



std::vector<std::pair<int,std::pair<int,std::string>>> check_file(){


    std::vector<std::pair<int,std::pair<int,std::string>>> output;

    std::string line;
    std::vector<int> indexes;
    int line_number = 1;
    while(get_next_line(line)){
        indexes = check_line(line);
        for(const auto &i : indexes){

            output.push_back(std::pair<int,std::pair<int,std::string>>(line_number,std::pair<int,std::string>(i,line)));
        }

        line_number++;
    }

    return output;

}
