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
add r2, r2, #32
sub sp, sp, r2
str r0, [sp, #28]
str r1, [sp, #32]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #32]
add r0, r0, r2
str r0, [sp, #8]
ldr r0, =printStringLn
ldr r1, [sp, #8]
ldr r1, [r1]
bl printf
str $t4, a
ldr r0, =#2
str r0, [sp, #0]
ldr r0, =#5
str r0, [sp, #0]
ldr r0, =#9
str r0, [sp, #0]
str $t9, b
ldr r0, =#2
str r0, [sp, #4]
ldr r0, =#0
str r0, [sp, #4]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #32]
add r0, r0, r2
str r0, [sp, #20]
ldr r0, [sp, #20]
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #32]
add r0, r0, r2
str r0, [sp, #24]
ldr r0, =printIntLn
ldr r1, [sp, #24]
bl printf
ENDmain:
ldr r0, [sp, #28]
mov r1, #4
mul r2, r0, r1
add r2, r2, #32
add sp, sp, r2
pop {pc}
