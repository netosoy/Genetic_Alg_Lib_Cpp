OBJS = PQ_in_Prim.tex
CC = pdflatex
TARGET = PQ_in_Prim.pdf
$(TARGET) : $(OBJS)
	$(CC) $(OBJS)
look : $(TARGET)
	okular $(TARGET) &
clean:
	rm -f *.log *.aux *.pdf
