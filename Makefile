OBJS	= main.o algos.o buffer.o output_formater.o
SOURCE	= main.cpp algos.cpp buffer.cpp output_formater.cpp
HEADER	= algos.h buffer.h output_formater.h
OUT	= main
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	main

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

algos.o: algos.cpp
	$(CC) $(FLAGS) algos.cpp 

buffer.o: buffer.cpp
	$(CC) $(FLAGS) buffer.cpp 

output_formater.o: output_formater.cpp
	$(CC) $(FLAGS) output_formater.cpp 

clean:
	rm -f $(OBJS) $(OUT)

run: main
	./main

