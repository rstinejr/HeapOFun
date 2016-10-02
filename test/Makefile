##############

MY_BIN_CFLAGS  = -g -O0
MY_BIN_LDFLAGS = -lstdc++ -lrt -lboost_unit_test_framework

PGM  = testHeap
INCS = ../includes
OBJS = testHeap.o 

.PHONY:	clean run 

all:	$(PGM)

$(PGM).o:	$(PGM).cpp
	g++ -Wall -g $(MY_BIN_CFLAGS) -I$(INCS) -c $(PGM).cpp -o $@

$(PGM):	$(INCS)/Heap.h

$(PGM):	$(OBJS)
	g++ -o $@ $(OBJS) $(MY_BIN_LDFLAGS)

clean:
	rm -f  $(PGM) $(PGM).o

test:	$(PGM)
	./$(PGM)
