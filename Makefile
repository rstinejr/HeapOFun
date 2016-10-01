.PHONY:	clean run

INCS = includes
MY_CFLAGS = -c -g -O0 -Wall -I$(INCS)
MY_LDFLAGS = -lstdc++ -lrt
OBJS = objs/main.o objs/Heap.o

PGM = testHeap

all:	$(PGM)

$(OBJS):	objs

objs/%.o:	src/%.cpp
	g++ $(MY_CFLAGS) $< -o $@

obj/main.o:	includes/Heap.h

obj/Heap.o:	includes/Heap.h

objs:	
	mkdir objs

$(PGM):	$(OBJS)
	g++ -o $@ $(OBJS) $(MY_LDFLAGS) 

clean:
	rm -rf objs $(PGM)
		
run:	$(PGM)
	./$(PGM)
