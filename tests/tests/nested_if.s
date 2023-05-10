.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "jfhdyb"
S_1: .asciz "not printed"

.section .text
.global main
.balign 4

main:
push {lr}
sub sp, sp, #8
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
bl printf
ldr r0, =#1
cmp r0, #0
beq IFFALSE_0
ldr r0, =#0
cmp r0, #0
beq IFFALSE_1
b ENDIF_1
IFFALSE_1:
ldr r0, =printStringLn
ldr r1, =S_0
bl printf
ENDIF_1:
b ENDIF_0
IFFALSE_0:
ldr r0, =printStringLn
ldr r1, =S_1
bl printf
ENDIF_0:
ENDmain:
add sp, sp, #8
pop {pc}

