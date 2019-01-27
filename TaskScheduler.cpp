
// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

// Example:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        vector<int> waiting(26);
        for (int i=0;i<tasks.size();i++) {
            char c = tasks[i];
            waiting[c - 'A']++; 
        }
        // for (auto t : waiting) {
        //     cout << t << " ";
        // }
        // cout << endl;
        sort(waiting.begin(), waiting.end());
        // for (auto t : waiting) {
        //     cout << t << " ";
        // }
        // cout << endl;
        while(waiting[25] > 0) {
            int i = 0;
            while( i <= n) {
                if (waiting[25] == 0)
                    break;
                if (i < 26 && waiting[25-i] > 0) {
                    waiting[25-i]--;
                }
                i++;
                time++;
            }
            sort(waiting.begin(), waiting.end());
        }
        return time;
    }
};

int main() {
    auto s = Solution();
    vector<char> tasks {'A', 'A', 'A', 'B', 'B', 'B'};
    auto answer = s.leastInterval(tasks, 2);
    cout << answer << endl;
}