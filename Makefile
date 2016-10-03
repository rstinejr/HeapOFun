.PHONY:	clean run test

INCS = includes
MY_CFLAGS = -c -g -O0 -Wall -I$(INCS)
MY_LDFLAGS = -lstdc++
OBJS = objs/main.o

PGM = testHeap

all:	$(PGM)

$(OBJS):	objs

objs/%.o:	src/%.cpp
	g++ $(MY_CFLAGS) $< -o $@

objs/main.o:	includes/Heap.h

objs:	
	mkdir objs

$(PGM):	$(OBJS)
	g++ -o $@ $(OBJS) $(MY_LDFLAGS) 

clean:
	rm -rf objs $(PGM)
	make -C test clean

test:	$(OBJS)
	make -C test test	

run:	$(PGM)
	./$(PGM)
