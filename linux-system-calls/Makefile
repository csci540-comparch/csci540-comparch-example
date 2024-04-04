GCC=gcc
GCC_FLAGS=-Wall -Werror -pedantic -g
INCLUDES=-Iinclude
RM=rm -rf
AS=as
LD=ld

process_src = process.c
exec_src = exec.c
file_src = file.c
info_src = info.c
echoall_src = echoall.c
syscall_src = syscall.s

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := .

process_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(process_src))
process_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(process_src))
PROCESS_TARGET=$(BIN_DIR)/process

exec_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(exec_src))
exec_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(exec_src))
EXEC_TARGET=$(BIN_DIR)/exec

file_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(file_src))
file_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(file_src))
FILE_TARGET=$(BIN_DIR)/file

info_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(info_src))
info_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(info_src))
INFO_TARGET=$(BIN_DIR)/info

echoall_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(echoall_src))
echoall_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(echoall_src))
ECHOALL_TARGET=$(BIN_DIR)/echoall

syscall_src := $(patsubst %.s, $(SRC_DIR)/%.s, $(syscall_src))
syscall_obj := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(syscall_src))
SYSCALL_TARGET=$(BIN_DIR)/syscall

.PHONY : all
all : $(PROCESS_TARGET) $(EXEC_TARGET) $(FILE_TARGET) $(INFO_TARGET) $(ECHOALL_TARGET) $(SYSCALL_TARGET)

$(PROCESS_TARGET) : $(process_obj)
	$(GCC) $(GCC_FLAGS) $(process_obj) -o $@

$(EXEC_TARGET) : $(exec_obj)
	$(GCC) $(GCC_FLAGS) $(exec_obj) -o $@

$(FILE_TARGET) : $(file_obj)
	$(GCC) $(GCC_FLAGS) $(file_obj) -o $@

$(INFO_TARGET) : $(info_obj)
	$(GCC) $(GCC_FLAGS) $(info_obj) -o $@

$(ECHOALL_TARGET) : $(echoall_obj)
	$(GCC) $(GCC_FLAGS) $(echoall_obj) -o $@

$(SYSCALL_TARGET) : $(syscall_obj)
	$(LD) $(syscall_obj) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(AS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY : clean
clean :
	$(RM) $(PROCESS_TARGET) $(EXEC_TARGET) $(FILE_TARGET) $(INFO_TARGET) $(ECHOALL_TARGET) $(SYSCALL_TARGET)
	$(RM) $(process_obj) $(exec_obj) $(file_obj) $(info_obj) $(echoall_obj) $(syscall_obj)
	$(RM) examplefile.txt
