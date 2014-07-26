CC = g++
OBJS = test.cpp helper.common.o maze.cAlgorithm.o maze.cAlgorithmDFS.o maze.cMaze.o
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = test
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
helper.common.o : helper.common.hh helper.common.cpp
	$(CC) $(CFLAGS) helper.common.cpp
maze.cAlgorithm.o : helper.cCell.hh maze.common.hh maze.cAlgorithm.hh maze.cAlgorithm.cpp
	$(CC) $(CFLAGS) maze.cAlgorithm.cpp
maze.cAlgorithmDFS.o : maze.cAlgorithmDFS.hh maze.cAlgorithmDFS.cpp
	$(CC) $(CFLAGS) maze.cAlgorithmDFS.cpp
maze.cMaze.o : maze.cMaze.hh maze.cMaze.cpp
	$(CC) $(CFLAGS) maze.cMaze.cpp
clean : 
	rm -f *.o *~ $(TARGET)
