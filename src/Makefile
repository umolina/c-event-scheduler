# List of paths to your include files, separated by commas (may be blank)
INCDIR = ../include

# List of flags to be passed to the C-compiler.
FLAGS = -g -Wall

# List of preprocessor defines, prefixed by -D and separated by spaces
DEFINES  =

# The directory of your source file (may be blank)
SRCDIR   = ..

# List of the source files to be compiled.
SOURCES  =  scheduler.c


CC=$(COMP)

all: scheduler test

scheduler: 
	$(CC) $(FLAGS) $(DEFINES) -I$(INCDIR) -c $(SOURCES) 

test: scheduler
	$(CC) $(FLAGS) $(DEFINES) -I$(INCDIR) -o test test.c *.o
	
clean:
	rm -f *.o test
