/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 18时37分43秒
 ************************************************************************/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) { 
        sort(A.begin(), A.end());
        int ans = 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] <= A[i - 1]) {
                int t = A[i - 1] + 1;
                ans += t - A[i];
                A[i] = t;
            }
        }
        return ans;
    }
};
