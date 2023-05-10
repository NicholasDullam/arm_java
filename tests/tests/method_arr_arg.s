.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

print_arr:
push {lr}
sub sp, sp, #28
str r0, [sp, #0]
ldr r0, =#0
str r0, [sp, #4]
ldr r0, [sp, #0]
ldr r0, [r0]
str r0, [sp, #12]
ldr r0, [sp, #12]
str r0, [sp, #8]
WLOOP_0:
ldr r0, [sp, #4]
ldr r1, [sp, #8]
mov r2, #0
cmp r0, r1
movlt r2, #1
str r2, [sp, #16]
ldr r0, [sp, #16]
cmp r0, #0
beq ENDWLOOP_0
ldr r0, [sp, #4]
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #20]
ldr r0, =printIntLn
ldr r1, [sp, #20]
bl printf
ldr r0, [sp, #4]
ldr r1, =#1
add r2, r0, r1
str r2, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #4]
b WLOOP_0
ENDWLOOP_0:
ldr r0, =#1
b ENDprint_arr
ENDprint_arr:
add sp, sp, #28
pop {pc}

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
ldr r0, =#3
add r0, r0, #1
lsl r0, r0, #2
bl malloc
str r0, [sp, #16]
ldr r1, =#3
str r1, [r0]
ldr r0, [sp, #16]
str r0, [sp, #4]
ldr r0, =#0
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#65
str r0, [r1, #0]
ldr r0, =#1
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#76
str r0, [r1, #0]
ldr r0, =#2
ldr r1, [sp, #4]
add r0, r0, #1
lsl r0, r0, #2
add r1, r1, r0
ldr r0, =#89
str r0, [r1, #0]
ldr r0, [sp, #4]
bl print_arr
str r0, [sp, #20]
ldr r0, [sp, #20]
str r0, [sp, #8]
ENDmain:
add sp, sp, #24
pop {pc}

