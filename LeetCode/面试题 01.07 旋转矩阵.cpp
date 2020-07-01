/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 09时59分10秒
 ************************************************************************/

// 空间复杂度: O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ss = matrix;
        int n = ss.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[j][n - i - 1] = ss[i][j];
            }
        }
    }
};

// 空间复杂度: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};