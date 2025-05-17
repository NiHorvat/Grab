
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
        int p = 0; // hash value for pattern
        int t = 0; // hash value for txt
        int h = 1;
        int d = 256; // d is the number of characters in the input alphabet
        // The value of h would be "pow(d, M-1)%q"
        for (i = 0; i < M - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first
        // window of text
        for (i = 0; i < M; i++)
        {
            p = (d * p + this->pattern[i]) % q;
            t = (d * t + line[i]) % q;
        }

        // Slide the pattern over text one by one
        for (i = 0; i <= N - M; i++)
        {

            // Check the hash values of current window of text
            // and pattern. If the hash values match then only
            // check for characters one by one
            if (p == t)
            {
                /* Check for characters one by one */
                for (j = 0; j < M; j++)
                {
                    if (line[i + j] != this->pattern[j])
                    {
                        break;
                    }
                }

                // if p == t and pat[0...M-1] = txt[i, i+1,
                // ...i+M-1]

                output.push_back(i);
            }

            // Calculate hash value for next window of text:
            // Remove leading digit, add trailing digit
            if (i < N - M)
            {
                t = (d * (t - line[i] * h) + line[i + M]) % q;

                // We might get negative value of t, converting
                // it to positive
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
