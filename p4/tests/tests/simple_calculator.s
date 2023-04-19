.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "x = "
S_1: .asciz "y = "
s: .asciz "Sum: "
d: .asciz "Difference: "
p: .asciz "Product: "
x: .word 19
y: .word 10

.section .text
.global main
.balign 4

add:
push {lr}
sub sp, sp, #12
str r0, [sp, #0]
str r1, [sp, #4]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
add r2, r0, r1
str r2, [sp, #8]
ldr r0, [sp, #8]
b ENDadd
ENDadd:
add sp, sp, #12
pop {pc}

subtract:
push {lr}
sub sp, sp, #12
str r0, [sp, #0]
str r1, [sp, #4]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
sub r2, r0, r1
str r2, [sp, #8]
ldr r0, [sp, #8]
b ENDsubtract
ENDsubtract:
add sp, sp, #12
pop {pc}

multiply:
push {lr}
sub sp, sp, #12
str r0, [sp, #0]
str r1, [sp, #4]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
mul r2, r0, r1
str r2, [sp, #8]
ldr r0, [sp, #8]
b ENDmultiply
ENDmultiply:
add sp, sp, #12
pop {pc}

main:
push {lr}
sub sp, sp, #32
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #16]
ldr r0, =printStringLn
ldr r1, [sp, #16]
bl printf
ldr r0, =printString
ldr r1, =S_0
bl printf
ldr r0, =printIntLn
ldr r1, =x
ldr r1, [r1, #0]
bl printf
ldr r0, =printString
ldr r1, =S_1
bl printf
ldr r0, =printIntLn
ldr r1, =y
ldr r1, [r1, #0]
bl printf
ldr r0, =printString
ldr r1, =s
bl printf
ldr r0, =x
ldr r0, [r0, #0]
ldr r1, =y
ldr r1, [r1, #0]
bl add
str r0, [sp, #20]
ldr r0, [sp, #20]
str r0, [sp, #4]
ldr r0, =printIntLn
ldr r1, [sp, #4]
bl printf
ldr r0, =printString
ldr r1, =d
bl printf
ldr r0, =x
ldr r0, [r0, #0]
ldr r1, =y
ldr r1, [r1, #0]
bl subtract
str r0, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #8]
ldr r0, =printIntLn
ldr r1, [sp, #8]
bl printf
ldr r0, =printString
ldr r1, =p
bl printf
ldr r0, =x
ldr r0, [r0, #0]
ldr r1, =y
ldr r1, [r1, #0]
bl multiply
str r0, [sp, #28]
ldr r0, [sp, #28]
str r0, [sp, #12]
ldr r0, =printIntLn
ldr r1, [sp, #12]
bl printf
ENDmain:
add sp, sp, #32
pop {pc}

