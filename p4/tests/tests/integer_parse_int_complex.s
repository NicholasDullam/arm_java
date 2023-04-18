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
add r2, r2, #28
sub sp, sp, r2
str r0, [sp, #24]
str r1, [sp, #28]
p©/üstr r0, [sp, #0]
p©/üstr r0, [sp, #4]
ldr r1, [sp, #20]
str r0, [sp, #8]
ldr r0, [sp, #0]
ldr r1, [sp, #4]
mul r2, r0, r1
str r2, [sp, #12]
ldr r0, =#300
ldr r1, [sp, #8]
mul r2, r0, r1
str r2, [sp, #16]
ldr r0, [sp, #12]
ldr r1, [sp, #16]
sub r2, r0, r1
str r2, [sp, #20]
ldr r0, =printIntLn
ldr r1, [sp, #20]
bl printf
ENDmain:
ldr r0, [sp, #24]
mov r1, #4
mul r2, r0, r1
add r2, r2, #28
add sp, sp, r2
pop {pc}

