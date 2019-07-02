// https://leetcode.com/problems/game-of-life/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class SolutionOld {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        vector< vector <int>> new_bord(board);
        std::copy(board.begin(), board.end(), back_inserter(new_bord));
        int neighbors_alive, neighbors_dead;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int cell = board[i][j];
                neighbors_alive = 0;
                neighbors_dead = 0;
                for(int a=-1;a<=1;a++) {
                    for(int b=-1;b<=1;b++) {
                        if(i+a>=0 && j+b>=0 && i+a<m && j+b<n&&
                        !(a==0&&b==0)) {
                            if (board[i+a][j+b] == 1)
                                neighbors_alive++;
                            else
                                neighbors_dead++;
                        }
                    }
                }

                if ( cell == 1 && (neighbors_alive < 2 || neighbors_alive > 3)) {
                    new_bord[i][j] = 0;
                } else if (cell ==1 && (neighbors_alive==2 || neighbors_alive==3)) {
                    new_bord[i][j] = 1;
                } else if (cell ==0 && neighbors_alive ==3 ) {
                    new_bord[i][j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                board[i][j] = new_bord[i][j];
            }
        }
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors_alive;
        int m = board.size();
        int n = m ? board[0].size() : 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int cell = board[i][j];
                neighbors_alive = 0;
                for(int a=-1;a<=1;a++) {
                    for(int b=-1;b<=1;b++) {
                        if(i+a>=0 && j+b>=0 && i+a<m && j+b<n &&
                        !(a==0&&b==0)) {
                            int tmp = board[i+a][j+b];
                            if (tmp == 1 || tmp == 2 )
                                neighbors_alive++;
                        }
                    }
                }

                if ( cell == 1 && (neighbors_alive < 2 || neighbors_alive > 3)) {
                    board[i][j] = 2;
                } else if (cell ==1 && (neighbors_alive==2 || neighbors_alive==3)) {
                    board[i][j] = 1;
                } else if (cell ==0 && neighbors_alive ==3 ) {
                    board[i][j] = -1;
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    auto s = Solution();
    vector< vector <int>> board {{0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}};
    s.gameOfLife(board);
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    // [0,0,0],
    // [1,0,1],
    // [0,1,1],
    // [0,1,0]
}