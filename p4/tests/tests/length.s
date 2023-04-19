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
sub sp, sp, #24
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
ldr r0, =#20
add r0, r0, #1
lsl r0, r0, #2
bl malloc
str r0, [sp, #16]
ldr r1, =#20
str r1, [r0]
ldr r0, [sp, #16]
str r0, [sp, #4]
ldr r0, [sp, #4]
ldr r0, [r0]
str r0, [sp, #20]
ldr r0, [sp, #20]
str r0, [sp, #8]
ldr r0, =printIntLn
ldr r1, [sp, #8]
bl printf
ENDmain:
add sp, sp, #24
pop {pc}

