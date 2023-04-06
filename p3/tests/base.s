.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"
t: .asciz "test"
s: .skip 4
f: .word 340
l: .word 200

.section .text
.global main
.balign 4

methodTest:
push {lr}
sub sp, sp, #4
str r0, [sp, #0]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, [sp, #0]
add sp, sp, #4
pop {pc}

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #28
sub sp, sp, r2
str r0, [sp, #24]
str r1, [sp, #28]
mov r0, #2
ldr r1, =f
str r0, [r1]
ldr r0, =f
ldr r0, [r0, #0]
str r0, [sp, #4]
mov r0, #3
str r0, [sp, #8]
mov r0, #4
bl methodTest
str r0, [sp, #16]
ldr r0, [sp, #16]
str r0, [sp, #4]
ldr r0, =printIntLn
ldr r1, [sp, #4]
bl printf
mov r0, #1
str r0, [sp, #0]
ldr r0, =t
ldr r1, =s
str r0, [r1]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =printStringLn
ldr r1, =s
ldr r1, [r1]
bl printf
mov r0, #0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #28]
ldr r0, [r0, r2]
str r0, [sp, #20]
ldr r0, =printStringLn
ldr r1, [sp, #20]
bl printf
ldr r0, [sp, #24]
mov r1, #4
mul r2, r0, r1
add r2, r2, #28
add sp, sp, r2
pop {pc}

