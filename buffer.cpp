#include "buffer.hpp"


class Buffer{

    private:
        size_t buffer_size = 0;
        std::string filename;


        std::ifstream file;
        std::istringstream iss;

        size_t curr_index = 0;
        std::vector<char> buffer;

    public:

        Buffer(std::string filename, size_t buffer_size = 1024){
            this->filename = filename;

            try
            {
                file.open(this->filename);
                if(!file.is_open()) throw "file not oppened properly";
            }
            catch(const std::exception& e)
            {
                std::cerr << "Buffer(std::string filename, size_t buffer_size = 1024)" << e.what() << '\n';
                exit(-1);
            }

            this->buffer_size = buffer_size;
            buffer.reserve(this->buffer_size);
        }


        bool get_next_chunk(){

            //std::cout << "-----New Chunk-----" << std::endl;

            this->file.read(this->buffer.data(),this->buffer_size);
            
            std::streamsize bytes_read = file.gcount();
            this->iss.str(std::string(this->buffer.data(),bytes_read));
            this->iss.clear();

            if(bytes_read > 0)
                return true;
            else
                return false;
            
        }

        bool get_next_line(std::string &line){
            
            
            if(getline(this->iss, line)){
                return true;
            }else if(get_next_chunk()){
                getline(this->iss,line);
                return true;
            }
            return false;
        }



        void change_buffer_size(size_t new_buffer_size){
            this->buffer_size = new_buffer_size;
            buffer.resize(this->buffer_size);
        }


        void clear(){
            this->buffer_size = 0;
            this->filename = "";


            this->file.clear();
            this->iss.clear();

            this->curr_index = 0;
            this->buffer.clear();

        }

};

Buffer *buff = nullptr;

bool init_buffer(std::string filename, size_t buffer_size = 1024){
    try
    {
        buff = new Buffer(filename,buffer_size);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << "init_buffer(std::string filename, size_t buffer_size = 1024) " << e.what() << '\n';
        exit(-1);
        
    }
}

void set_buffer(size_t buffer_size){
    try
    {
        buff->change_buffer_size(buffer_size);
    }
    catch(const std::exception& e)
    {
        std::cerr << "void set_buffer(size_t buffer_size)" << e.what() << '\n';
        exit(-1);
    }
    
}

bool get_next_line(std::string &line){

    try
    {
        return buff->get_next_line(line);
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << "std::string get_next_chunk()" << e.what() << '\n';
        exit(-1);
    }

}

void buffer_clear(){

    buff->clear();

}

