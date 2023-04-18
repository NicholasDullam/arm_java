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
mov r3, #4
mul r2, r0, r3
add r2, r2, #12
sub sp, sp, r2
str r0, [sp, #8]
str r1, [sp, #12]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #12]
add r0, r0, r2
str r0, [sp, #0]
ldr r0, =printStringLn
ldr r1, [sp, #0]
ldr r1, [r1]
bl printf
bl get_bool
str r0, [sp, #4]
ldr r0, [sp, #4]
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
ldr r0, [sp, #8]
mov r1, #4
mul r2, r0, r1
add r2, r2, #12
add sp, sp, r2
pop {pc}

