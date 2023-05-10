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
sub sp, sp, #20
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
ldr r0, =#1
str r0, [sp, #4]
WLOOP_0:
ldr r0, [sp, #4]
ldr r1, =#10
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #12]
ldr r0, [sp, #12]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, =printIntLn
ldr r1, [sp, #4]
bl printf
ldr r0, [sp, #4]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #16]
ldr r0, [sp, #16]
str r0, [sp, #4]
b WLOOP_0
ENDWLOOP_0:
ENDmain:
add sp, sp, #20
pop {pc}

