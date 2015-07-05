CC=clang++
INC=-I/usr/include
CFLAGS=-std=c++11 -lSDL2 -lSDL2_image
LIBNAME=sdl2ecs.a
LIBOBJS=component.o display.o entity.o game.o input.o renderer.o system.o texture.o time.o transform.o

all: test

main:
	clang++ -o main main.cc $(LIBNAME) $(CFLAGS)

test:
	clang++ -o test test.cc $(INC) $(CFLAGS)

lib: component display entity game input renderer system texture time transform
	ar rcs $(LIBNAME) $(LIBOBJS)

component:
	clang++ -c component.cc

display:
	clang++ -c display.cc

entity:
	clang++ -c entity.cc -DLIBCOMPILE

game:
	clang++ -c game.cc -DLIBCOMPILE

input:
	clang++ -c input.cc

prefabs:
	clang++ -c prefabs.cc

renderer:
	clang++ -c renderer.cc $(CFLAGS) -DLIBCOMPILE

system:
	clang++ -c system.cc

texture:
	clang++ -c texture.cc -DLIBCOMPILE

time:
	clang++ -c time.cc -DLIBCOMPILE

transform:
	clang++ -c transform.cc

wasdcontroller:
	clang++ -c wasdcontroller.cc

clean:
	rm -f *.o
