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
add r2, r2, #56
sub sp, sp, r2
str r0, [sp, #52]
str r1, [sp, #56]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #56]
add r0, r0, r2
str r0, [sp, #16]
ldr r0, =printStringLn
ldr r1, [sp, #16]
ldr r1, [r1]
bl printf
str $t4, a
ldr r0, =#1
str r0, [sp, #0]
ldr r0, =#2
str r0, [sp, #0]
ldr r0, =#4
str r0, [sp, #0]
str $t9, b
ldr r0, =#5
str r0, [sp, #4]
ldr r0, =#3
str r0, [sp, #4]
ldr r0, =#0
str r0, [sp, #4]
ldr r0, =#0
str r0, [sp, #8]
ldr r0, =#2
str r0, [sp, #12]
WLOOP_0:
ldr r0, [sp, #12]
ldr r1, =#0
mov r2, #0
cmp r0, r1
movge r2, #1
str r2, [sp, #28]
ldr r0, [sp, #28]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #12]
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #56]
add r0, r0, r2
str r0, [sp, #32]
ldr r0, [sp, #12]
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #56]
add r0, r0, r2
str r0, [sp, #36]
ldr r0, [sp, #32]
ldr r1, [sp, #36]
mul r2, r0, r1
str r2, [sp, #40]
ldr r0, [sp, #8]
ldr r1, [sp, #40]
add r2, r0, r1
str r2, [sp, #44]
ldr r0, [sp, #44]
str r0, [sp, #8]
ldr r0, [sp, #12]
ldr r1, =#1
sub r2, r0, r1
str r2, [sp, #48]
ldr r0, [sp, #48]
str r0, [sp, #12]
b WLOOP_0
ENDWLOOP_0:
ldr r0, =printIntLn
ldr r1, [sp, #8]
bl printf
ENDmain:
ldr r0, [sp, #52]
mov r1, #4
mul r2, r0, r1
add r2, r2, #56
add sp, sp, r2
pop {pc}

