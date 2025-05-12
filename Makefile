OBJS	= main.o algos.o buffer.o output_formater.o program_options.o
SOURCE	= main.cpp algos.cpp buffer.cpp output_formater.cpp program_options.cpp
HEADER	= algos.hpp buffer.hpp output_formater.hpp program_options.hpp
OUT	= grab
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	grab

grab: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

algos.o: algos.cpp
	$(CC) $(FLAGS) algos.cpp 

abuffer.o: buffer.cpp
	$(CC) $(FLAGS) buffer.cpp 

output_formater.o: output_formater.cpp
	$(CC) $(FLAGS) output_formater.cpp 

program_options.o: program_options.cpp
	$(CC) $(FLAGS) program_options.cpp 

clean:
	rm -f $(OBJS) $(OUT)

run: grab
	./grab

