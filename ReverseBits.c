/* Reverse bits of a given 32 bits unsigned integer. */

/* For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000). */

uint32_t reverseBits(uint32_t n) {
    uint32_t m;
    for(int i=1;i<32;i++)
    {
        m |= (n&0x1);
        n >>= 1;
        m <<= 1;
    }
    m |= (n&0x1);
    return m;
}
