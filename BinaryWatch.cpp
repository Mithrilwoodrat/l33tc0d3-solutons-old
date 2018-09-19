#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> answer;
    vector<int> weight = {8,4,2,1,32, 16, 8 ,4, 2, 1};
    vector<string> readBinaryWatch(int num) {
        backtrack(num,0, 0, 0);
        return answer;
    }
    void backtrack(int i, int j, int hour,int min) {
        //cout << "i " << i << "hour: " << hour << "min: " << min<<endl;
        if ((hour > 12) || (min >= 60) || (hour==12 && min ==0))
            return;
        if (i==0) {
            string tmp = to_str(hour, min);
            //cout << tmp << endl;
            answer.push_back(tmp);
            return;
        } else if (j < 10 && i <= 10 - j && i > 0) {
            backtrack(i, j+1, hour ,min);
            if (j >= 4){
                backtrack(i-1, j+1, hour , min + weight[j]);
            }else {
                backtrack(i-1, j+1,hour+weight[j] , min);
            }
        }
    }
    string to_str(int hour, int min) {
        string answer;
        answer= to_string(hour);
        answer = answer + ":";
        if (min < 10) {
            answer = answer + "0" + to_string(min);
        } else {
            answer = answer + to_string(min);
        }
        return answer;
    }
};

int main() {
 auto s = Solution();
 auto answer = s.readBinaryWatch(2);
 for (auto &s:answer)
     cout << s << endl;
}