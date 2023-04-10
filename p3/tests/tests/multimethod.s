.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

method1:
push {lr}
sub sp, sp, #4
str r0, [sp, #0]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =#9
add sp, sp, #4
pop {pc}

method2:
push {lr}
sub sp, sp, #4
str r0, [sp, #0]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =#4
add sp, sp, #4
pop {pc}

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
ldr r0, [r0, r2]
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
bl printf
ldr r0, =#9
bl method1
str r0, [sp, #8]
ldr r0, =#4
bl method2
str r0, [sp, #12]
ldr r0, [sp, #8]
ldr r1, [sp, #12]
sub r2, r0, r1
str r2, [sp, #16]
ldr r0, [sp, #16]
str r0, [sp, #0]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, [sp, #20]
mov r1, #4
mul r2, r0, r1
add r2, r2, #24
add sp, sp, r2
pop {pc}

