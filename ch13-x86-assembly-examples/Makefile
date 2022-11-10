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
executables = gas-64bit-1 gas-64bit-2 gas-64bit-3 callsum security-1 security-2 security-3 

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
.PHONY : all
all : $(executables)

## gas-64bit-1
##              : Build and link together first 64-bit x86 assembly example
##
gas-64bit-1 : gas-64bit-1.s
	as gas-64bit-1.s -o gas-64bit-1.o
	ld gas-64bit-1.o -o gas-64bit-1

## gas-64bit-2
##              : Build and link together second 64-bit x86 assembly example
##
gas-64bit-2 : gas-64bit-2.s
	as gas-64bit-2.s -o gas-64bit-2.o
	gcc -static gas-64bit-2.o -o gas-64bit-2

## gas-64bit-3
##              : Build and link together third 64-bit x86 assembly example
##
gas-64bit-3 : gas-64bit-3.s
	as gas-64bit-3.s -o gas-64bit-3.o
	gcc -static gas-64bit-3.o -o gas-64bit-3

## callsum
##              : Build callsum example of using float values in gas/c
callsum : sum.s callsum.c
	as sum.s -o sum.o
	gcc -c callsum.c -o callsum.o
	gcc -static sum.o callsum.o -o callsum

## security-1
##              : Build and link together first security x86 assembly example
##
security-1 : security-1.s
	as --march=i386 --32 ./security-1.s -o security-1.o
	ld -m elf_i386  security-1.o -o security-1	

## security-2
##              : Build and link together second x86 assembly example
##
security-2 : security-2.s
	as --march=i386 --32 ./security-2.s -o security-2.o
	ld -m elf_i386  security-2.o -o security-2	

## security-3
##              : Build and link together third x86 assembly example
##
security-3 : security-3.s
	as --march=i386 --32 ./security-3.s -o security-3.o
	ld -m elf_i386  security-3.o -o security-3	

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
