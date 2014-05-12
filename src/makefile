OBJS = GA_Mutation.cpp Random.o Threading.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBIG) -pedantic
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -lpthread -o $(TARGET)
Threading.o : Threading.hh Threading.cpp
	$(CC) $(CFLAGS) Threading.cpp -lpthread
Random.o : Random.hh Random.cpp Threading.o
	$(CC) $(CFLAGS) Random.cpp
clean:
	rm -f *.o $(TARGET) *~
