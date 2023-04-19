.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "cs352"

.section .text
.global main
.balign 4

get_string:
push {lr}
sub sp, sp, #0
ldr r0, =S_0
b ENDget_string
ENDget_string:
add sp, sp, #0
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
ldr r0, =printString
ldr r1, [sp, #8]
bl printf
bl get_string
str r0, [sp, #12]
ldr r0, [sp, #12]
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
bl printf
ENDmain:
add sp, sp, #16
pop {pc}

