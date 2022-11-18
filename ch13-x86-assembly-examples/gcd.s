# -----------------------------------------------------------------------------
# A 64-bit function that returns calculates greatest common denominator of 
# two unsigned inteters.  The function has the signature
#
#   unsigned int gcd(unsigned int a, unsigned int b)
# 
# Example from Stallings COA textbook (9th edition), Figure 15.4 hand
# crafted assembly program for greatest common divisor.
#
# We modified the Figure 15.4 for 64 bit x86 architecture here.  Parameters
# are passed in as registers %edi and %esi rather than %eax and %edx respectively.
# But return result is still returned in %eax register in x86-64 architecture.
# 
# Also the NASM examples from textbook have opcodes specified as
#    sub destination, source
# So sub eax, edx gives a result of eax = eax - edx
#
# But in gas, the order is
#     sub source, destination
# So sub %esi, %edi gives a result of %edi = %edi - %esi
#
# Parameters:
#   First parameter called a is passed in in register %edi
#   Second parameter called b is passed in register %esi
# 
# Returns:
#    Returns greatest common divisor in eax register.  Had to add in
#    exchange instruction to exchange the result we calculated in %edi into
#    %eax register for return.
# -----------------------------------------------------------------------------

        .global gcd2
        .text
gcd2:
        neg     %edi            # if a/edi == 0 then negating is still 0 so result is equal
        je      L3              # if a/edi == 0, jump to L3, should end up returning b/esi as result
L1:     neg     %edi            # negate a/edi to undo previous negation, so now a/edi has original value
        xchg    %esi, %edi      # we know a/edi is not 0, so after exchange, b/esi is not 0
L2:     sub     %esi, %edi      # a/edi = a/edi - a/esi, a/esi is not 0 so this subtraction does something
        jg      L2              # if result is still positive, then need to keep subtracting
        jne     L1              # this will jump if result in a/edi was negative, which will make the value positive again
                                # the previous 2 jumps happen when result is positive or negative, if result was 0 we are done
L3:     add     %esi, %edi      # at this point a/edi should be 0, so this add copies b/esi into a/edi
        jne     L4              # if b/esi was 0 for previous add, then a/esi is also 0, and result was equal
        inc     %edi            # if the result of add at L3 was equal, then both are 0, so need to return 1 by definition
L4:     xchg    %edi, %eax      # result is calculated in a/edi but needs to be returned in %eax
        ret
