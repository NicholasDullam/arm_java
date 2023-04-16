.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.balign 4

method:
push {lr}
sub sp, sp, #4
str r0, [sp, #0]
ldr r0, =printIntLn
ldr r1, [sp, #0]
bl printf
ldr r0, =#3
b ENDmethod
ENDmethod:
add sp, sp, #4
pop {pc}

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #20
sub sp, sp, r2
str r0, [sp, #16]
str r1, [sp, #20]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #20]
add r0, r0, r2
str r0, [sp, #8]
ldr r0, =printStringLn
ldr r1, [sp, #8]
ldr r1, [r1]
bl printf
ldr r0, =#352
str r0, [sp, #0]
ldr r0, [sp, #0]
bl method
str r0, [sp, #12]
ldr r0, [sp, #12]
str r0, [sp, #4]
ldr r0, =printIntLn
ldr r1, [sp, #4]
bl printf
ENDmain:
ldr r0, [sp, #16]
mov r1, #4
mul r2, r0, r1
add r2, r2, #20
add sp, sp, r2
pop {pc}

