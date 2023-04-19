.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

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
str r0, [sp, #12]
ldr r0, =printStringLn
ldr r1, [sp, #12]
bl printf
ldr r0, =#0
str r0, [sp, #4]
WLOOP_0:
ldr r0, [sp, #4]
ldr r1, =#5
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, =#0
str r0, [sp, #8]
WLOOP_1:
ldr r0, [sp, #8]
ldr r1, [sp, #4]
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #20]
ldr r0, [sp, #20]
cmp r0, #0
beq ENDWLOOP_1
ldr r0, =printIntLn
ldr r1, [sp, #8]
bl printf
ldr r0, [sp, #8]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #8]
b WLOOP_1
ENDWLOOP_1:
ldr r0, [sp, #4]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #28]
ldr r0, [sp, #28]
str r0, [sp, #4]
b WLOOP_0
ENDWLOOP_0:
ENDmain:
add sp, sp, #32
pop {pc}

