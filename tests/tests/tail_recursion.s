.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

factorial:
push {lr}
sub sp, sp, #32
str r0, [sp, #0]
str r1, [sp, #4]
ldr r0, [sp, #0]
ldr r1, =#1
mov r2, #0
cmp r0, r1
moveq r2, #1
str r2, [sp, #8]
ldr r0, [sp, #0]
ldr r1, =#0
mov r2, #0
cmp r0, r1
moveq r2, #1
str r2, [sp, #12]
ldr r0, [sp, #8]
ldr r1, [sp, #12]
orr r2, r1, r0
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq IFFALSE_0
ldr r0, [sp, #4]
b ENDfactorial
b ENDIF_0
IFFALSE_0:
ldr r0, [sp, #0]
ldr r1, =#1
sub r2, r0, r1
str r2, [sp, #20]
ldr r0, [sp, #4]
ldr r1, [sp, #0]
mul r2, r0, r1
str r2, [sp, #24]
ldr r0, [sp, #20]
ldr r1, [sp, #24]
bl factorial
str r0, [sp, #28]
ldr r0, [sp, #28]
b ENDfactorial
ENDIF_0:
ldr r0, =#1
b ENDfactorial
ENDfactorial:
add sp, sp, #32
pop {pc}

main:
push {lr}
sub sp, sp, #16
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
ldr r1, =#1
bl factorial
str r0, [sp, #12]
ldr r0, [sp, #12]
str r0, [sp, #4]
ldr r0, =printIntLn
ldr r1, [sp, #4]
bl printf
ENDmain:
add sp, sp, #16
pop {pc}

