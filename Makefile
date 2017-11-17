## Daniel Hayden & Frank Rooney
## Date: 17/11/17
## Makefile using gcc
## GLUT & GLEW for OpenGL

CC=gcc
CFLAGS=-lX11 -lGL -lGLU -lglut -I. 
APP=Wator

build: main.o
	$(CC) -o $(APP) main.o $(CFLAGS)

clean:
	rm *.o