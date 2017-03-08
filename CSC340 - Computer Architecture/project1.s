#Matt Meglan
#2/7/13
#MIPS Program that computes exponents

.data#
	base: .word 1
	expo: .word 1
	count: .word 0
	result: .word 1
	i: .word 0
	entexpo: .asciiz "Enter an exponent: "	
	entbase: .asciiz "Enter a base: "
	star: .asciiz "**"
	newline: .asciiz "\n"
	equals: .asciiz "="
	end: .asciiz " exponentials have been computed. Toodles!\n";


.text

	

.globl main
	#resister usage
	#$t0 = base
	#$t1 = expo
	#$t2 = count
	#$t3 = result
	#$t4 = i

main:
	lw $t0, base
	lw $t1, expo
	lw $t2, count
	lw $t3, result
	lw $t4, i

	topofloop:
	la $a0, entbase
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 5
	syscall

	add $t0, $0, $v0
	
	beq $t0, $0 outofloop
	la $a0, entexpo
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 5
	syscall

	add $t1, $0, $v0

	addi $t4, $0, 1
	addi $t3, $0, 1
 
	expoloop:
	bgt $t4, $t1 expobloop
	
	mul $t3, $t3, $t0
	addi $t4, $t4, 1
	b expoloop

	expobloop:	

	add $a0, $t0, $0
	addi $v0, $0, 1
	syscall

	la $a0, star
	addi $v0, $0, 4
	syscall

	add $a0, $t1, $0
	addi $v0, $0, 1
	syscall

	la $a0, equals
	addi $v0, $0, 4
	syscall

	add $a0, $t3, $0
	addi $v0, $0, 1
	syscall

	la $a0, newline
	addi $v0, $0, 4
	syscall 
	syscall 

	addi $t2, $t2, 1
	b topofloop

	outofloop:

	add $a0, $t2, $0
	addi $v0, $0, 1
	syscall

	la $a0, end
	addi $v0, $0, 4
	syscall

	#exit
	li $v0, 10
	syscall