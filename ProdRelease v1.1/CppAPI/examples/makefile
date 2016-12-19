CC = g++
FLAGS = -Wall
LIBS = ../Smeshalist.a ../../lib/libprotobuf.a
INCLUDE = -I/home/test/Pobrane/protobuf/src -I../include

all:
	$(CC) $(FLAGS) $(INCLUDE) -c Example01.cpp -o Example01.o
	$(CC) -o Example01 Example01.o $(LIBS)
	rm *.o
