# -----------------------------------------------------------------------------
# A 64-bit function that returns calculates greatest common denominator of 
# two unsigned inteters.  The function has the signature
#
#   unsigned int gcd(unsigned int a, unsigned int b)
# -----------------------------------------------------------------------------

        .global gcd2
        .text
gcd2:
        neg     %edi
        je      L3
L1:     neg     %edi
        xchg    %esi, %edi
L2:     sub     %esi, %edi
        jg      L2
        jne     L1 
L3:     add     %esi, %edi
        jne     L4
        inc     %edi
L4:     xchg    %edi, %eax
        ret
