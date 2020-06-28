class Solution14 {
    public static String longestCommonPrefix(String[] strs) {
        StringBuffer answer = new StringBuffer();
        int len = strs.length;
        if (0 == len || strs[0].isEmpty()) {
            return "";
        }
        if (1 == len) {
            return strs[0];
        }
        int i = 0;
        while(true) {
            if (i >= strs[0].length()) {
                break;
            }
            char c = strs[0].charAt(i);            
            for (int j=1; j < len;j++) {
                if (strs[j].isEmpty()) {
                    return "";
                }
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return answer.toString();
                }
                
            }
            answer.append(c);
            i ++;
        }
        return answer.toString();
    }

    public static void main(final String[] args) {

        // int input = 10;
        // System.out.println(numSquares(input));
        String[] strs = {"flower","flow","flight"};
        System.out.println(longestCommonPrefix(strs));
    }
}