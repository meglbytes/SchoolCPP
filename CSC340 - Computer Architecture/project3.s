#Matt Meglan
#4/15/13
#MIPS program that esitmates square roots of numbers

.data#
	two: .double 2.0
	int: .word 1		
	prompt: .asciiz "Tolerance please: "
	prompt2: .asciiz "Real number please (negative to end): "
	prompt3: .asciiz "Square root of x is " 
	newline: .asciiz "\n"	
	
.text

.globl main
	#register usage
	#f0 temp 
	#f2 epsilon
	#f4 y
	#f6 x
	#f8 c
	#f10 temp
	#f12 temp
	#f14 0
	#f16 two
	
main:
	l.d $f16, two
	mov.d $f4, $f16 #intialize f4 so its greater than 0
	
	la $a0, prompt
	addi $v0, $0, 4
	syscall		#print string 

	addi $v0, $0, 7 
	syscall         #read double (into $f0)
	
	la $a0, newline
        addi $v0, $0, 4
        syscall

	mov.d $f2, $f0 #put $f0 into $f2
	
	sub.d $f14, $f0, $f0

	topofloop: 

	c.lt.d $f4, $f14  #if y is negative break loop
	bc1t breakloop   #branch co-processor 

	la $a0, prompt2 #print string
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 7
	syscall 	#read double (into $f0)
       
	la $a0, newline
	addi $v0, $0, 4

	mov.d $f4, $f0 #put $f0 into $f4	

	div.d $f6, $f4, $f16 #y/2

	mul.d $f10, $f6, $f6 #square x
	sub.d $f8, $f10, $f4 #(x*x) - y

	abs.d $f8, $f8

	topofloop2:
        abs.d $f8, $f8

	c.le.d $f8, $f2 #if e is less than or equal c then condition true
	bc1t breakloop2  #break loop if condition true
	
	l.d $f10, two #load two into $f10
	mul.d $f12, $f10, $f6 #x * 2 into $f12
	div.d $f10, $f8, $f12 #c / $f12
	sub.d $f6, $f6, $f10 #x - $f10 into x
	mul.d $f10, $f6, $f6 #square x
        sub.d $f8, $f10, $f4 #(x*x) - y
 	
	b topofloop2
	breakloop2:
	#mul.d $f0, $f0, $f0

	la $a0, prompt3	
	li $v0, 4
	syscall		# print string

	mov.d $f12, $f6
	li $v0, 3
	syscall		# print double (from $f12)

	la $a0, newline	 
	li $v0, 4
	syscall 	# newline
		
	b topofloop
	
	breakloop:

#exit
li $v0, 10
syscall
