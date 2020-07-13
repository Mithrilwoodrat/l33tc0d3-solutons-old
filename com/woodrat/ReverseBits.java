package com.woodrat;


// n = 1011 m = 0
// loop1 m=0001 m=0010 n=0101
// loop2 m=0011 m=0110 n=0010
// loop3 m=0110 m=1100 n=0001
// loop4 m=1101
class Solution190 {
    // you need treat n as an unsigned value
    public static int reverseBits(int n) {
        int m = 0;
        for(int i=0;i<32;i++) {
            m = m | (n&0x1);
            m = m << 1;
            n = n >> 1;
        }
        return m;
    }

    public static void main(final String[] args) {
        System.out.println(reverseBits(-3));
    }
}