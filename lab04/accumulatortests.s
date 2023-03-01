.import lotsofaccumulators.s

.data
inputarray: .word 1,2,3,4,5,6,7,0

TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
# Tests if the given implementation of accumulate is correct.
#Input: a0 contains a pointer to the version of accumulate in question. See lotsofaccumulators.s for more details
#
#
#
#The main function currently runs a simple test that checks if accumulator works on the given input array. All versions of accumulate should pass this.
#Modify the test so that you can catch the bugs in four of the five solutions!
main:
    la a0 inputarray

    # for accumulatorone
    li s0 123

    # for accumulatortwo
    li t0 1234
    addi sp sp -8
    sw t0 4(sp)

    # for accumulatorfour
    li t2 123

    #jal accumulatorone
    #jal accumulatortwo
    #jal accumulatorthree
    #jal accumulatorfour
    #jal accumulatorfive

    # for accumulatorone
    li t0 123
    bne s0 t0 Fail

    # for accumulatortwo
    lw t0 4(sp)
    addi sp sp 8
    li t1 1234
    bne t0 t1 Fail

    li t0 28
    beq a0 t0 Pass

    # for accumulatorfive
    la a0 inputarray
    sw zero 0(a0)
    jal accumulatorfive
    beqz a0 Pass
Fail:
    la a0 TestFailed
    jal print_string
    j End
Pass:
    la a0 TestPassed
    jal print_string
End:
    jal exit

print_int:
	mv a1 a0
    li a0 1
    ecall
    jr ra
    
print_string:
	mv a1 a0
    li a0 4
    ecall
    jr ra
    
exit:
    li a0 10
    ecall
