.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "not printed"

.section .text
.global main
.balign 4

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #24
sub sp, sp, r2
str r0, [sp, #20]
str r1, [sp, #24]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #24]
add r0, r0, r2
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
ldr r1, [r1]
bl printf
ldr r0, =#0
cmp r0, #0
beq IFFALSE_0
ldr r0, =printStringLn
adr r1, S_0
ldr r1, [r1]
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =#6
str r0, [sp, #0]
WLOOP_0:
ldr r0, [sp, #0]
ldr r1, =#0
mov r2, #0
cmp r0, r1
movgt r2, #1
str r2, [sp, #8]
ldr r0, [sp, #8]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #0]
ldr r1, =#9
add r2, r0, r1
str r2, [sp, #12]
ldr r0, =printIntLn
ldr r1, [sp, #12]
bl printf
ldr r0, [sp, #0]
ldr r1, =#1
sub r2, r0, r1
str r2, [sp, #16]
ldr r0, [sp, #16]
str r0, [sp, #0]
b WLOOP_0
ENDWLOOP_0:
ENDIF_0:
ENDmain:
ldr r0, [sp, #20]
mov r1, #4
mul r2, r0, r1
add r2, r2, #24
add sp, sp, r2
pop {pc}

