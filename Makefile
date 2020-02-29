PROG = secureSocket
CC = g++
CPPFLAGS = -L/usr/lib
LDFLAGS = -lssl -lcrypto
FLAGS = -Wall -ggdb

OBJS = server.o

all: $(PROG) .depend

$(PROG): $(OBJS)
	g++ -o $@ $(OBJS) $(LDFLAGS)

.depend:
	-@$(CC) $(CPPFLAGS) -MM $(OBJS:.o=.cpp) > $@ 2> /dev/null

-include .depend

clean:
	rm -f *stackdump $(PROG) *.o .depend
