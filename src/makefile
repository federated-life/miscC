IDIR =../include
CC=gcc
CFLAGS=-O0 -g -Wall -Wextra -std=c89 -pedantic-errors -I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm
INCLUDE=-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/include/
LDFLAGS=-L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/usr/lib/
LDLIBS=-lcurl

_DEPS = api_header.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#
# the _OBJ files need to match to *.c files
#

_OBJ = api_calls.o api_funcs.o parson.o api_ll.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

theexecutable: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) $(LDLIBS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	rm -f theexecutable
