
class Solution {
    public static int romanToInt(String s) {
        int length = s.length();
        int i = 0;
        int result = 0;
        char c;
        while(i<length) {
            c = s.charAt(i);
            if (c == 'I') {
                i++;
                if (i < length) {
                    c = s.charAt(i);
                    if (c == 'V') {
                        i++;
                        result += 4;
                        continue;
                    } else if (c == 'X') {
                        i++;
                        result += 9;
                        continue;
                    }
                }
                result += 1;
            } else if (c == 'V') {
                i++;
                result += 5;
            } else if (c == 'X') {
                i++;
                if (i < length) {
                    c = s.charAt(i);
                    if ( c == 'L') {
                        i++;
                        result += 40;
                        continue;
                    } else if ( c == 'C' ) {
                        i++;
                        result += 90;
                        continue;
                    }
                }
                result += 10;
                
            } else if ( c == 'L') {
                i++;
                result += 50;
            } else if ( c== 'C') {
                i++;
                c = s.charAt(i);
                if (i < length) {
                    if (c == 'D') {
                        i++;
                        result += 400;
                        continue;
                    } else if ( c == 'M' ) {
                        i++;
                        result += 900;
                        continue;
                    }
                } 
                result += 100;
            } else if ( c == 'D') {
                i++;
                result += 500;
            } else if ( c == 'M' ) {
                i++;
                result += 1000;
            }
        }
        return result;
    }

    public static void main(String[] argv) {
        int result = romanToInt("MDLXX");
        System.out.println(result);
        result = romanToInt("IV");
        System.out.println(result);
        result = romanToInt("IX");
        System.out.println(result);
        result = romanToInt("LVIII");
        System.out.println(result);
        result = romanToInt("MCMXCIV");
        System.out.println(result);
    }
}