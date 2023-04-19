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
sub sp, sp, #56
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #20]
ldr r0, =printStringLn
ldr r1, [sp, #20]
bl printf
ldr r0, =#3
add r0, r0, #1
lsl r0, r0, #2
bl malloc
str r0, [sp, #24]
ldr r1, =#3
str r1, [r0]
ldr r0, [sp, #24]
str r0, [sp, #4]
ldr r0, =#0
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#1
str r0, [r1, #0]
ldr r0, =#1
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#2
str r0, [r1, #0]
ldr r0, =#2
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#4
str r0, [r1, #0]
ldr r0, =#3
add r0, r0, #1
lsl r0, r0, #2
bl malloc
str r0, [sp, #28]
ldr r1, =#3
str r1, [r0]
ldr r0, [sp, #28]
str r0, [sp, #8]
ldr r0, =#0
ldr r1, [sp, #8]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#5
str r0, [r1, #0]
ldr r0, =#1
ldr r1, [sp, #8]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#3
str r0, [r1, #0]
ldr r0, =#2
ldr r1, [sp, #8]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#0
str r0, [r1, #0]
ldr r0, =#0
str r0, [sp, #12]
ldr r0, =#2
str r0, [sp, #16]
WLOOP_0:
ldr r0, [sp, #16]
ldr r1, =#0
mov r2, #0
cmp r0, r1
movge r2, #1
str r2, [sp, #32]
ldr r0, [sp, #32]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #16]
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #4]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #36]
ldr r0, [sp, #16]
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #8]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #40]
ldr r0, [sp, #36]
ldr r1, [sp, #40]
mul r2, r0, r1
str r2, [sp, #44]
ldr r0, [sp, #12]
ldr r1, [sp, #44]
add r2, r0, r1
str r2, [sp, #48]
ldr r0, [sp, #48]
str r0, [sp, #12]
ldr r0, [sp, #16]
ldr r1, =#1
sub r2, r0, r1
str r2, [sp, #52]
ldr r0, [sp, #52]
str r0, [sp, #16]
b WLOOP_0
ENDWLOOP_0:
ldr r0, =printIntLn
ldr r1, [sp, #12]
bl printf
ENDmain:
add sp, sp, #56
pop {pc}

