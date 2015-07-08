CC=clang++
SRCPATH=src/
INCPATH=api/include/
LIBPATH=api/lib/
LDFLAGS=-lSDL2 -lSDL2_image -lsdl2ecs
CFLAGS=-std=c++11 -L$(LIBPATH) -Wall -Wunused-variable
LIBNAME=libsdl2ecs.a
LIBOBJS=component.o display.o entity.o game.o input.o renderer.o system.o texture.o time.o transform.o

main:
	./prefab-generator.py
	./scene-generator.py
	$(CC) $(CFLAGS) -o main main.cc $(LDFLAGS)
	rm prefabs.hh
	rm main.scene

lib: component display entity game input renderer system texture time transform
	ar rcs $(LIBNAME) $(LIBOBJS)
	rm -f *.o
	mv $(LIBNAME) $(LIBPATH)
	rm -f $(INCPATH)*.h
	cp $(SRCPATH)*.h $(INCPATH)

component:
	$(CC) -c $(SRCPATH)component.cc


display:
	$(CC) -c $(SRCPATH)display.cc


entity:
	$(CC) -c $(SRCPATH)entity.cc -DLIBCOMPILE


game:
	$(CC) -c $(SRCPATH)game.cc -DLIBCOMPILE


input:
	$(CC) -c $(SRCPATH)input.cc


prefabs:
	$(CC) -c $(SRCPATH)prefabs.cc


renderer:
	$(CC)  -c $(SRCPATH)renderer.cc -std=c++11 -DLIBCOMPILE


system:
	$(CC) -c $(SRCPATH)system.cc


texture:
	$(CC) -c $(SRCPATH)texture.cc -DLIBCOMPILE


time:
	$(CC) -c $(SRCPATH)time.cc -DLIBCOMPILE


transform:
	$(CC) -c $(SRCPATH)transform.cc


clean:
	rm -f $(LIBPATH)$(LIBNAME)
