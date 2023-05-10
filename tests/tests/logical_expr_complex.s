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
sub sp, sp, #36
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
ldr r1, =#1
and r2, r1, r0
str r2, [sp, #4]
ldr r0, =#0
ldr r1, [sp, #4]
orr r2, r1, r0
str r2, [sp, #8]
ldr r0, =#1
mvn r0, r0
str r0, [sp, #12]
ldr r0, =#1
ldr r1, [sp, #12]
and r2, r1, r0
str r2, [sp, #16]
ldr r0, [sp, #8]
ldr r1, [sp, #16]
orr r2, r1, r0
str r2, [sp, #20]
ldr r0, [sp, #20]
mvn r0, r0
str r0, [sp, #24]
ldr r0, [sp, #24]
cmp r0, #0
beq IFFALSE_0
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #28]
ldr r0, =printStringLn
ldr r1, [sp, #28]
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =#1
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #32]
ldr r0, =printStringLn
ldr r1, [sp, #32]
bl printf
ENDIF_0:
ENDmain:
add sp, sp, #36
pop {pc}

