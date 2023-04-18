.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

get_arr:
push {lr}
sub sp, sp, #28
str r0, [sp, #0]
ldr r0, [sp, #0]
add r0, r0, #1
lsl r1, r0, #2
bl malloc
str r0, [sp, #12]
ldr r1, [sp, #0]
str r1, [r0]
ldr r0, [sp, #12]
str r0, [sp, #4]
ldr r0, =#0
str r0, [sp, #8]
WLOOP_0:
ldr r0, [sp, #8]
ldr r1, [sp, #0]
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #8]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #20]
ldr r0, [sp, #8]
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, [sp, #20]
str r0, [r1]
ldr r0, [sp, #8]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #8]
b WLOOP_0
ENDWLOOP_0:
ldr r0, [sp, #4]
b ENDget_arr
ENDget_arr:
add sp, sp, #28
pop {pc}

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #36
sub sp, sp, r2
str r0, [sp, #32]
str r1, [sp, #36]
ldr r0, =#3
str r0, [sp, #0]
ldr r0, [sp, #0]
bl get_arr
str r0, [sp, #12]
ldr r0, [sp, #12]
str r0, [sp, #4]
ldr r0, =#0
str r0, [sp, #8]
WLOOP_1:
ldr r0, [sp, #8]
ldr r1, [sp, #0]
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq ENDWLOOP_1
ldr r0, [sp, #8]
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #36]
add r0, r0, r2
str r0, [sp, #20]
ldr r0, =printInt
ldr r1, [sp, #20]
bl printf
ldr r0, [sp, #8]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #8]
b WLOOP_1
ENDWLOOP_1:
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #36]
add r0, r0, r2
str r0, [sp, #28]
ldr r0, =printStringLn
ldr r1, [sp, #28]
ldr r1, [r1]
bl printf
ENDmain:
ldr r0, [sp, #32]
mov r1, #4
mul r2, r0, r1
add r2, r2, #36
add sp, sp, r2
pop {pc}

