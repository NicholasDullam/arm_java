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
mov r3, #4
mul r2, r0, r3
add r2, r2, #36
sub sp, sp, r2
str r0, [sp, #32]
str r1, [sp, #36]
ldr r0, =#0
ldr r1, =#1
and r2, r1, r0
str r2, [sp, #0]
ldr r0, =#0
ldr r1, [sp, #0]
orr r2, r1, r0
str r2, [sp, #4]
ldr r0, =#1
mvn r0, r0
str r0, [sp, #8]
ldr r0, =#1
ldr r1, [sp, #8]
and r2, r1, r0
str r2, [sp, #12]
ldr r0, [sp, #4]
ldr r1, [sp, #12]
orr r2, r1, r0
str r2, [sp, #16]
ldr r0, [sp, #16]
mvn r0, r0
str r0, [sp, #20]
ldr r0, [sp, #20]
cmp r0, #0
beq IFFALSE_0
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #36]
add r0, r0, r2
str r0, [sp, #24]
ldr r0, =printStringLn
ldr r1, [sp, #24]
ldr r1, [r1]
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =#1
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #36]
add r0, r0, r2
str r0, [sp, #28]
ldr r0, =printStringLn
ldr r1, [sp, #28]
ldr r1, [r1]
bl printf
ENDIF_0:
ENDmain:
ldr r0, [sp, #32]
mov r1, #4
mul r2, r0, r1
add r2, r2, #36
add sp, sp, r2
pop {pc}
