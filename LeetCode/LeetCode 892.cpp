/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 11时42分00秒
 ************************************************************************/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) continue;
                ans += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                if(i > 0 && grid[i - 1][j]) ans -= min(grid[i - 1][j], grid[i][j]) * 2;
                if(j > 0 && grid[i][j - 1]) ans -= min(grid[i][j - 1], grid[i][j]) * 2; 
            }
        }
        return ans;
    }
};
