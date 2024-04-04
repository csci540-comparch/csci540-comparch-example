# @file syscallasm.s
# @brief Linux system calls from ISA assembly level
#
# Example of calling read and write system calls from
# x86_64 assembly.  There are several methods to
# invoke a system call, for example you can invoke
# interrupt 80, or use the newer syscall
# instructions, as shown here.

	# declare system call identifiers
	.equ 	SYS_WRITE, 	1
	.equ	SYS_READ,	0
	.equ	SYS_EXIT,	60

	# declare standard file descriptors
	.equ	STDIN,		0
	.equ	STDOUT,		1
	
	.global _start

	.data	# data sections hold initialized constant data
user_msg:
	.ascii "Please enter text: "
	user_len = . - user_msg
	
disp_msg:
	.ascii "You have entered: "
	disp_len = . - disp_msg

	.bss	# bss sections hold uninitialized data, e.g. variables to hold stuff
num:
	.space 10
	num_len = . - num
	
	.text 	# text section is actually where executable code goes
_start:
	# user prompt write(1, userMsg, userLen)
	mov 	$SYS_WRITE, %rax 	# system call is a write
	mov 	$STDOUT, %rdi 		# file descriptor 1 is stdout
	mov 	$user_msg, %rsi 	# address of string to output
	mov 	$user_len, %rdx		# number of bytes to output
	syscall

	# read and store the user input read(0, num, numLen)
	mov	$SYS_READ, %rax		# system call is a read
	mov	$STDIN, %rdi		# file descriptor 0 is stdin
	mov	$num, %rsi		# address where input is saved
	mov	$num_len, %rdx		# number of bytes to read
	syscall

	# output message write(1, dispMsg, dispLen)
	mov 	$SYS_WRITE, %rax 	# system call is a write
	mov 	$STDOUT, %rdi 		# file descriptor 1 is stdout
	mov 	$disp_msg, %rsi 	# address of string to output
	mov 	$disp_len, %rdx		# number of bytes to output
	syscall
	
	# output the number entered write(1, num, numLen)
	mov 	$SYS_WRITE, %rax 	# system call is a write
	mov 	$STDOUT, %rdi 		# file descriptor 1 is stdout
	mov 	$num, %rsi 		# address of string to output
	mov 	$num_len, %rdx		# number of bytes to output
	syscall
	
	# exit(0)
	mov 	$SYS_EXIT, %rax		# system call 60 is exit
	mov 	$42, %rdi		# exit status code
	syscall
	
