/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 09时41分45秒
 ************************************************************************/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y, flag = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'R') {
                    x = i;
                    y = j;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        int ans = 0;
        for(int i = y + 1; i < board[x].size(); i++) {
            if(board[x][i] == 'B') break;
            if(board[x][i] == 'p') {
                ans++;
                break;
            }
        }
        for(int i = y - 1; i >= 0; i--) {
            if(board[x][i] == 'B') break;
            if(board[x][i] == 'p') {
                ans++;
                break;
            }
        }
        for(int i = x - 1; i >= 0; i--) {
            if(board[i][y] == 'B') break;
            if(board[i][y] == 'p') {
                ans++;
                break;
            }
        }
        for(int i = x + 1; i < board.size(); i++) {
            if(board[i][y] == 'B') break;
            if(board[i][y] == 'p') {
                ans++;
                break;
            }
        }
        return ans;
    }
};
