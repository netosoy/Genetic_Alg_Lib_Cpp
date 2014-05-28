OBJS = test.cpp GA_Mutation.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = test
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
GA_Mutation.o : GA_Mutation.hh GA_Mutation.cpp
	$(CC) $(CFLAGS) GA_Mutation.cpp
clean : 
	rm -f *.o *~ $(TARGET)
