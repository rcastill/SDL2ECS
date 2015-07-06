CC=clang++
CFLAGS=-std=c++11 -lSDL2 -lSDL2_image
LIBNAME=sdl2ecs.a
LIBOBJS=component.o display.o entity.o game.o input.o renderer.o system.o texture.o time.o transform.o

main:
	clang++ -o main main.cc $(LIBNAME) $(CFLAGS)

lib: component display entity game input renderer system texture time transform
	ar rcs $(LIBNAME) $(LIBOBJS)
	rm -f *.o

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

clean:
	rm -f *.o
