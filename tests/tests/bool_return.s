.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
S_0: .asciz "not printed"
S_1: .asciz "egrl"

.section .text
.global main
.balign 4

get_bool:
push {lr}
sub sp, sp, #0
ldr r0, =#0
b ENDget_bool
ENDget_bool:
add sp, sp, #0
pop {pc}

main:
push {lr}
sub sp, sp, #12
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #4]
ldr r0, =printStringLn
ldr r1, [sp, #4]
bl printf
bl get_bool
str r0, [sp, #8]
ldr r0, [sp, #8]
cmp r0, #0
beq IFFALSE_0
ldr r0, =printStringLn
ldr r1, =S_0
bl printf
b ENDIF_0
IFFALSE_0:
ldr r0, =printStringLn
ldr r1, =S_1
bl printf
ENDIF_0:
ENDmain:
add sp, sp, #12
pop {pc}

