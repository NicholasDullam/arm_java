.section .data
printIntLn: .asciz "%d\n"
printStringLn: .asciz "%s\n"
printInt: .asciz "%d"
printString: .asciz "%s"

.section .text
.global main
.global main
.balign 4

main:
push {lr}
mov r3, #4
mul r2, r0, r3
add r2, r2, #4
sub sp, sp, r2
str r0, [sp, #0]
str r1, [sp, #4]
ldr r0, [sp, #0]
mov r1, #4
mul r2, r0, r1
add r2, r2, #4
add sp, sp, r2
pop {pc}

