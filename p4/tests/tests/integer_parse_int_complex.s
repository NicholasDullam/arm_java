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
add r2, r2, #52
sub sp, sp, r2
str r0, [sp, #48]
str r1, [sp, #52]
ldr r0, =#0
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #52]
add r0, r0, r2
str r0, [sp, #12]
ldr r0, [sp, #12]
ldr r0, [r0]
bl atoi
str r0, [sp, #16]
ldr r0, [sp, #16]
str r0, [sp, #0]
ldr r0, =#1
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #52]
add r0, r0, r2
str r0, [sp, #20]
ldr r0, [sp, #20]
ldr r0, [r0]
bl atoi
str r0, [sp, #24]
ldr r0, [sp, #24]
str r0, [sp, #4]
ldr r0, =#2
add r0, r0, #1
mov r1, #4
mul r2, r0, r1
ldr r0, [sp, #52]
add r0, r0, r2
str r0, [sp, #28]
ldr r0, [sp, #28]
ldr r0, [r0]
bl atoi
str r0, [sp, #32]
ldr r0, [sp, #32]
str r0, [sp, #8]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
mul r2, r0, r1
str r2, [sp, #36]
ldr r0, =#300
ldr r1, [sp, #8]
mul r2, r0, r1
str r2, [sp, #40]
ldr r0, [sp, #36]
ldr r1, [sp, #40]
sub r2, r0, r1
str r2, [sp, #44]
ldr r0, =printIntLn
ldr r1, [sp, #44]
bl printf
ENDmain:
ldr r0, [sp, #48]
mov r1, #4
mul r2, r0, r1
add r2, r2, #52
add sp, sp, r2
pop {pc}

