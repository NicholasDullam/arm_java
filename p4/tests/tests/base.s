.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "test"
S_1: .asciz "testing"
S_2: .asciz "test"
S_3: .asciz "4lllllllllllllllllllll"

.section .text
.global main
.balign 4

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #12
sub sp, sp, r2
str r0, [sp, #8]
str r1, [sp, #12]
ldr r0, =#0
cmp r0, #0
beq IFFALSE_0
ldr r0, =S_0
bl strlen
mov r1, r0
ldr r0, =S_1
bl strlen
add r0, r0, r1
bl malloc
str r0, [sp, #0]
ldr r0, =S_0
ldr r1, =S_1
bl strcat
ldr r1, [sp, #0]
str r0, [r1]
ldr r0, =printStringLn
ldr r1, [sp, #0]
ldr r1, [r1]
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =S_2
bl strlen
mov r1, r0
ldr r0, =S_3
bl strlen
add r0, r0, r1
bl malloc
str r0, [sp, #4]
ldr r0, =S_2
ldr r1, =S_3
bl strcat
ldr r1, [sp, #4]
str r0, [r1]
ldr r0, =printStringLn
ldr r1, [sp, #4]
ldr r1, [r1]
bl printf
ENDIF_0:
ENDmain:
ldr r0, [sp, #8]
mov r1, #4
mul r2, r0, r1
add r2, r2, #12
add sp, sp, r2
pop {pc}

