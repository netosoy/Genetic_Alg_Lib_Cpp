OBJS = test.cpp GA_Crossover.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = test
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
GA_Crossover.o : GA_Crossover.hh GA_Crossover.cpp
	$(CC) $(CFLAGS) GA_Crossover.cpp
clean : 
	rm -f *.o *~ $(TARGET)
