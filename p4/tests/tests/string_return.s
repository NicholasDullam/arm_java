.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

get_string:
push {lr}
sub sp, sp, #0
ldr r0, =STR_0
add sp, sp, #0
pop {pc}

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #16
sub sp, sp, r2
str r0, [sp, #12]
str r1, [sp, #16]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #16]
ldr r0, [r0, r2]
str r0, [sp, #4]
ldr r0, =printString
ldr r1, [sp, #4]
bl printf
bl get_string
str r0, [sp, #8]
ldr r0, [sp, #8]
str r0, [sp, #0]
ldr r0, =printStringLn
ldr r1, [sp, #0]
bl printf
ldr r0, [sp, #12]
mov r1, #4
mul r2, r0, r1
add r2, r2, #16
add sp, sp, r2
pop {pc}

