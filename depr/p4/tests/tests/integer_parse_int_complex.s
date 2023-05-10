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
sub sp, sp, #52
str r0, [r1]
str r1, [sp, #0]
ldr r0, =#0
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #16]
ldr r0, [sp, #16]
bl atoi
str r0, [sp, #20]
ldr r0, [sp, #20]
str r0, [sp, #4]
ldr r0, =#1
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #24]
ldr r0, [sp, #24]
bl atoi
str r0, [sp, #28]
ldr r0, [sp, #28]
str r0, [sp, #8]
ldr r0, =#2
add r1, r0, #1
lsl r1, r1, #2
ldr r0, [sp, #0]
add r0, r0, r1
ldr r0, [r0]
str r0, [sp, #32]
ldr r0, [sp, #32]
bl atoi
str r0, [sp, #36]
ldr r0, [sp, #36]
str r0, [sp, #12]
ldr r0, [sp, #4]
ldr r1, [sp, #8]
mul r2, r0, r1
str r2, [sp, #40]
ldr r0, =#300
ldr r1, [sp, #12]
mul r2, r0, r1
str r2, [sp, #44]
ldr r0, [sp, #40]
ldr r1, [sp, #44]
sub r2, r0, r1
str r2, [sp, #48]
ldr r0, =printIntLn
ldr r1, [sp, #48]
bl printf
ENDmain:
add sp, sp, #52
pop {pc}

