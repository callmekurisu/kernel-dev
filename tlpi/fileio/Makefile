#Makefile for TLPI ch4

# Source, Executable, Includes, Library Defines
TLPI    = ../lib
INCL    = $(TLPI)/error_functions.h $(TLPI)/get_num.h $(TLPI)/tlpi_hdr.h $(TLPI)/ename.c.inc
SRC     = seek_io.c error_functions.c get_num.c
OBJ     = $(SRC:.c=.o)
EXE     = seek_io

# Compiler, Linker Defines
CC      = /usr/bin/gcc
CFLAGS  = -ansi -pedantic -Wall -O2
LDFLAGS = -o $(EXE)
CFDEBUG = -ansi -pedantic -Wall -g -DDEBUG $(LDFLAGS)
RM      = /bin/rm -f
	
# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -I$(TLPI) -c $(CFLAGS) $*.c $(TLPI)/*.c

# # Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Objects depend on these Libraries
$(OBJ): $(INCL)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) core a.out
