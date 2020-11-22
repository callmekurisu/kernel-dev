# Makefile for TLPI ch4
# Update line 7 with main file
# Source, Executable, Includes, Library Defines
TLPI    = ../lib
EF      = error_functions
GN      = get_num
MAIN    = seek_io
INCL    = $(TLPI)/$(EF).h $(TLPI)/$(GN).h $(TLPI)/tlpi_hdr.h $(TLPI)/ename.c.inc
SRC     = $(MAIN).c $(EF).c $(GN).c
OBJ     = $(SRC:.c=.o)
EXE     = $(MAIN)

# Compiler, Linker Defines
CC      = /usr/bin/gcc
CFLAGS  = -ansi -pedantic -Wall -O2
LDFLAGS = -o $(EXE)
RM      = /bin/rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CC) -I$(TLPI) -c $(CFLAGS) $*.c $(TLPI)/*.c

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

# Objects depend on these Libraries
$(OBJ): $(INCL)

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) core a.out
