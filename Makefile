CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics	-lsfml-window -lsfml-system
DEPS = FibLFSR.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm *.o PhotoMagic