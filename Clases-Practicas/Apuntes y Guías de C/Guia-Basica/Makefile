CC = gcc 
CFLAGS = -Wall
TARGET = guiabasica

all: $(TARGET)

$(TARGET): guiabasica.o
	$(CC) $(CFLAGS) $^ -o $@

guiabasica.o: guiabasica.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o guiabasica


.PHONY: all clean 


# Ejercico