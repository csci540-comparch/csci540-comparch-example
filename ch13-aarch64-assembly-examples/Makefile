# compiler flags, tools and include variables
GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -g -O0 -pg
INCLUDES=-I../../include
LINKS=-lpthread

BEAUTIFIER=uncrustify
BEAUTIFIER_FLAGS=-c ../../config/.uncrustify.cfg --replace --no-backup

DOC=doxygen
DOC_FLAGS=../../config/Doxyfile

RM=rm -rf

# source files in this project (for beautification)
PROJECT_NAME=comparch
sources = 
executables = gas-aarch64-1 

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
.PHONY : all
all : $(executables)

## gas-aarch64-1
##              : Build and link together first 64-bit ary64 assembly example
##
gas-aarch64-1 : gas-aarch64-1.s
	as gas-aarch64-1.s -o gas-aarch64-1.o
	ld --static gas-aarch64-1.o -o gas-aarch64-1


## beautify     : Run the code beautifier by hand if needed
##
.PHONY : beautify
beautify :
	$(BEAUTIFIER) $(BEAUTIFIER_FLAGS) $(sources)


## unit-tests   : Run executables to test them
##
.PHONY : unit-tests
unit-tests :
	./security-1


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(executables) *.exe *.o *.gch *.out *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
