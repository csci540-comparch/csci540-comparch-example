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
all : assg04-cache-performance

## assg04-cache-performance
##              : Build and link together assg04-cache-performance example
##
assg04-cache-performance : assg04-cache-performance.o
	$(GCC) $(GCC_FLAGS) $< $(LINKS) -o $@


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
	$(RM) assg04-cache-performance *.exe *.o *.gch *~


## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $^
