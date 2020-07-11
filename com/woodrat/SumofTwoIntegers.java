package com.woodrat;

//https://leetcode.com/problems/sum-of-two-integers/
//https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

// a = 0011 (3) b = 1001 (9)
// loop1 sum = 1010 (a ^ b) carry = 0010 ( (a&b) <<1 ) 
// loop2 sum = 1000 (a ^ b) carry = 0100 ((a&b)<<1)
// loop end sum = 1100 (12 a^b) carry = 0000

class Solution371 {
    public static int getSum(int a, int b) {
        if (a==0) {return b;}
        if (b==0) {return a;}
        while(b!=0) {
            int carry = a&b;
            a = a ^ b;
            b = (carry) << 1;
        }
        return a;
    }
    public static void main(final String[] args) {
        System.out.println(getSum(1, 2));
    }
}