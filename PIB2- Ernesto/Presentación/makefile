OBJS = presentation.tex
CC = pdflatex
TARGET = presentation.pdf
$(TARGET) : $(OBJS)
	$(CC) $(OBJS)
look : $(TARGET)
	okular $(TARGET) &
clean:
	rm -f *.log *.aux *.pdf *.nav *.out *.snm *.toc *.vrb *.gz
