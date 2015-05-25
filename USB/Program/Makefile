all: FYP2015

CC=gcc
CXX=g++

COBJS=./hidapi/hid.o
CPPOBJS=./code/main.o ./code/src/setup.o ./code/src/task.o ./code/src/KBHIT.o
OBJS=$(COBJS) $(CPPOBJS)

IDIR=./hidapi ./code/inc

CFLAGS+=$(IDIR:%=-I%) -Wall -g -c
LIBS=-framework IOKit -framework CoreFoundation


FYP2015: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o FYP2015.exe

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f *.o FYP2015 $(CPPOBJS) $(COBJS)

.PHONY: clean
