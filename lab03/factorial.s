.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    beq a0, zero, exit_factorial
    mv t1, a0
    addi a0, a0, -1
    addi sp, sp, -8
    sw t1, 0(sp)
    sw ra, 4(sp)
    jal factorial
    lw t1, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8
    mul a0, t1, a0
    ret
exit_factorial:
    li a0, 1
    ret

