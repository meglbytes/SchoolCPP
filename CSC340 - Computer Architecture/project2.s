#Matt Meglan
#3/19/13
#MIPS Program taht computes exponents

.data#
	int: .word 1
	prompt: .asciiz "Please provide an integer: "
	message: .asciiz "The next prime number is: "
	newline: .asciiz "\n"	
	
.text

.globl main
	#register usage
	#$t0 = int
	#$t1 = tempip
	#$t2 = mod
	#$t3 = count
	#$t4 = div
	#$t5 = temp
	#$t6 = temp
	
main:
	la $a0, promt
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 5
	syscall

	add $t0, $0, $v0

	la $a0, newline
	addi $v0, $0, 4
	syscall
	syscall

	add $a0, $t0
	jal nextprime
	add $t6, $0, $v0

	la $a0, message
	addi $v0, $0, 4
	syscall

	add $a0, $t6, $0
	addi $v0, $0, 1
	syscall

	la #a0, newline
	addi $v0, $0, 4
	syscall
	syscall	

#exit
li $v0, 10
syscall

isprime:
	addi $t5, $0, 2
	dive $a0, $t5
	mflo $t4
	addi $t3, $0, 2
	
	topofloop:

	bge $t3, $t4 exitipp
	beq $a0, 0 exitip
	beq $a0, 1 exitip

	div $a0, $t3
	mfhi $t2, #$t2 = $a0 mod $t3
	beq $t2, 0 exitip
	addi #t3, $t3, 1
	b topofloop
	
	exitip:
	addi $v0, $0, 0
	jr $ra

	exitipp:
	addi $v0, $0, 1
	jr $ra

nextprime:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	topofloopnp:
	jal isprime
	beq $v0, $0 not prime
	add $v0, $0, $a0
	b prime

	notprime addi $a0, $a0, 1
	b topofloopnp

	prime: lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra