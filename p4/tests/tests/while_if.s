.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "Fizz"
S_1: .asciz "Buzz"

.section .text
.global main
.balign 4

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #28
sub sp, sp, r2
str r0, [sp, #24]
str r1, [sp, #28]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #28]
add r0, r0, r2
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
ldr r1, [r1]
bl printf
ldr r0, =#6
str r0, [sp, #0]
WLOOP_0:
ldr r0, =#1
neg r0, r0
str r0, [sp, #8]
ldr r0, [sp, #0]
ldr r1, [sp, #8]
mov r2, #0
cmp r0, r1
movgt r2, #1
str r2, [sp, #12]
ldr r0, [sp, #12]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #0]
ldr r1, =#2
mov r2, #0
cmp r0, r1
movge r2, #1
str r2, [sp, #16]
ldr r0, [sp, #16]
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
ldr r0, [sp, #0]
ldr r1, =#1
sub r2, r0, r1
str r2, [sp, #20]
ldr r0, [sp, #20]
str r0, [sp, #0]
b WLOOP_0
ENDWLOOP_0:
ENDmain:
ldr r0, [sp, #24]
mov r1, #4
mul r2, r0, r1
add r2, r2, #28
add sp, sp, r2
pop {pc}
