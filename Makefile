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


## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##
.PHONY : all
all : assg04-cache-performance ch12-littlendian ch13-x86-assembly-1 ch13-x86-assembly-2 ch13-x86-assembly-3

## assg04-cache-performance
##              : Build and link together assg04-cache-performance example
##
assg04-cache-performance : assg04-cache-performance.o
	$(GCC) $(GCC_FLAGS) $< $(LINKS) -o $@

## ch10-computer-arithmetic
##              : Build and link together arithmetic
##
ch10-computer-arithmetic : ch10-computer-arithmetic.o
	$(GCC) $(GCC_FLAGS) $< $(LINKS) -o $@


## ch12-littlendian
##              : Build and link together littlendian example
##
ch12-littlendian : ch12-littlendian.o
	$(GCC) $(GCC_FLAGS) $< $(LINKS) -o $@

## ch13-x86-assembly-1
##              : Build and link together first x86 assembly example
##
ch13-x86-assembly-1 :
	@echo "\n\033[33;1mBuilding GAS Hello World\033[0m"
	as --march=i386 --32 ./ch13-x86-assembly-1.s -o ch13-x86-assembly-1.o
	ld -m elf_i386  ch13-x86-assembly-1.o -o ch13-x86-assembly-1	

## ch13-x86-assembly-2
##              : Build and link together second x86 assembly example
##
ch13-x86-assembly-2 :
	@echo "\n\033[33;1mBuilding GAS Hello World second example\033[0m"
	as --march=i386 --32 ./ch13-x86-assembly-2.s -o ch13-x86-assembly-2.o
	ld -m elf_i386  ch13-x86-assembly-2.o -o ch13-x86-assembly-2	

## ch13-x86-assembly-3
##              : Build and link together third x86 assembly example
##
ch13-x86-assembly-3 :
	@echo "\n\033[33;1mBuilding GAS Hello World third example\033[0m"
	as --march=i386 --32 ./ch13-x86-assembly-3.s -o ch13-x86-assembly-3.o
	ld -m elf_i386  ch13-x86-assembly-3.o -o ch13-x86-assembly-3	

%.o: %.cpp
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

## beautify     : Run the code beautifier by hand if needed
##y
.PHONY : beautify
beautify :
	$(BEAUTIFIER) $(BEAUTIFIER_FLAGS) $(sources)


## unit-tests   : Run executables to test them
.PHONY : unit-tests
unit-tests :
	./assg04-cache-performance


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) assg04-cache-performance ch12-littlendian ch13-x86-assembly-1 ch13-x86-assembly-2 ch13-x86-assembly-3 *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
