/*************************************************************************
	> File Name: ccc.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月16日 星期四 10时17分48秒
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> ss;
        for(int i = 0; i < intervals.size(); i++) {
            int fir = intervals[i][0];
            int sec = intervals[i][1];
            if(!ss.size() || ss.back()[1] < fir) {
                ss.push_back({fir, sec});
            }
            else ss.back()[1] = max(ss.back()[1], sec);
        }
        return ss;
    }
};
