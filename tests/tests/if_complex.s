.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "not printed"
S_1: .asciz "skduf"

.section .text
.global main
.balign 4

main:
push {lr}
sub sp, sp, #28
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #8]
ldr r0, =printStringLn
ldr r1, [sp, #8]
bl printf
ldr r0, =#6
str r0, [sp, #4]
ldr r0, =#1
ldr r1, =#3
add r2, r0, r1
str r2, [sp, #12]
ldr r0, [sp, #12]
ldr r1, =#4
mul r2, r0, r1
str r2, [sp, #16]
ldr r0, [sp, #16]
ldr r1, =#10
sub r2, r0, r1
str r2, [sp, #20]
ldr r0, [sp, #20]
ldr r1, [sp, #4]
mov r2, #0
cmp r0, r1
movne r2, #1
str r2, [sp, #24]
ldr r0, [sp, #24]
cmp r0, #0
beq IFFALSE_0
ldr r0, =printStringLn
ldr r1, =S_0
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =printStringLn
ldr r1, =S_1
bl printf
ENDIF_0:
ENDmain:
add sp, sp, #28
pop {pc}

