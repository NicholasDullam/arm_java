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
add r2, r2, #16
sub sp, sp, r2
str r0, [sp, #12]
str r1, [sp, #16]
mov r0, #2 @ literal declaration
neg r0, r0
str r0, [sp, #0]
ldr r0, [sp, #0] @ temp reference
rsbpl r0, r0, #0
str r0, [sp, #4]
mov r0, #2 @ literal declaration
ldr r1, [sp, #4] @ temp reference
add r2, r0, r1
str r2, [sp, #8]
ldr r0, =printInt
ldr r1, [sp, #8] @ temp reference
bl printf
ldr r0, [sp, #12]
mov r1, #4
mul r2, r0, r1
add r2, r2, #16
add sp, sp, r2
pop {pc}

