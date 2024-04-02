GCC=g++
GCC_FLAGS=-Wall -Werror -pedantic -g -std=c++20
INCLUDES=-Iinclude
RM=rm -rf

race_src = race.cpp \
					 prime.cpp \
					 Buffer.cpp \
					 Consumer.cpp \
					 Producer.cpp \
					 Resumable.cpp

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := .

race_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(race_src))
race_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(race_src))
RACE_TARGET=$(BIN_DIR)/race


.PHONY : all
all : $(RACE_TARGET)

$(RACE_TARGET) : $(race_obj)
	$(GCC) $(GCC_FLAGS) $(race_obj) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY : clean
clean :
	$(RM) $(RACE_TARGET)
	$(RM) $(race_obj)