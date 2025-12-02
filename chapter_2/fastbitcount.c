// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. Use this observation to write a faster version of
// bitcount.

/*x &= (x-1) works because subtracting 1 from x flips all the bits to the right
of the rightmost 1-bit, including the rightmost 1-bit itself. When we perform
the bitwise AND operation between x and (x-1), all bits to the left of the
rightmost 1-bit remain unchanged, the rightmost 1-bit becomes 0, and all bits to
the right of it also become 0. Thus, this operation effectively removes the
rightmost 1-bit from x.*/
/* fastbitcount: count 1 bits in x using x &= (x-1) */
int fastbitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}
