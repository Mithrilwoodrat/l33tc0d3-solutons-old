class Solution {
public:
    int myAtoi(string str) {
        unsigned int n = 0;
        bool negative = false;
    
        int i = 0;
        str = str.erase(0, str.find_first_not_of(" \t\n\r"));

    
        int len = str.length();
        if (len == 0)
            return 0;
        unsigned int cutoff = UINT32_MAX /10 + 1;
        if ((str[0] == '-') || (str[0]== '+')) {
            i += 1;
            if (str[0] == '-') {
                negative = true;
            }
        }
    

        for (; i < len ; i++) {

            if (!((str[i] >= '0') && (str[i] <= '9'))) {
                break;
            }
            if (n > cutoff) {
                n =  UINT32_MAX;
                break;
            }
            auto v = str[i] - '0';
 
            n *= 10;
            unsigned int n1 = n + v;
            if (n1 < n || n1 > UINT32_MAX) {
                n =  UINT32_MAX;
                break;
            }
            n += v;

        }
        //check over flow
        if (negative) {
            if (n > INT32_MIN) {
                return INT32_MIN;
            } else {
                return -n;
            }
        } else if (n > INT32_MAX) {
            return INT32_MAX;
        }
        return n;
        }
};
