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
add r2, r2, #24
sub sp, sp, r2
str r0, [sp, #20]
str r1, [sp, #24]
ldr r0, =#0
cmp r0, #0
beq IFFALSE_0
WLOOP_0:
ldr r0, =#0
mvn r0, r0
str r0, [sp, #0]
ldr r0, =#1
mvn r0, r0
str r0, [sp, #4]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
and r2, r1, r0
str r2, [sp, #8]
ldr r0, =#10
ldr r1, =#10
mov r2, #0
cmp r1, r0
movne r2, #1
str r2, [sp, #12]
ldr r0, [sp, #8]
ldr r1, [sp, #12]
and r2, r1, r0
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq ENDWLOOP_0
b WLOOP_0
ENDWLOOP_0:
b ENDIF_0
IFFALSE_0:
ENDIF_0:
ldr r0, [sp, #20]
mov r1, #4
mul r2, r0, r1
add r2, r2, #24
add sp, sp, r2
pop {pc}

