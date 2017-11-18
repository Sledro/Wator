## Daniel Hayden & Frank Rooney
## Date: 17/11/17
## Makefile using g++

CC=g++
CFLAGS=-g -c -Wall -std=c++11 
LDFLAGS=
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp Grid.h Grid.cpp Fish.h Fish.cpp Shark.h Shark.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LIBFLAGS)

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)