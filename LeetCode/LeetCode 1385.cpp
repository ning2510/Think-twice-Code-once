class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int x, ans = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int flag = 1;
            for(int j = 0; j < arr2.size(); j++) {
                x = abs(arr1[i] - arr2[j]);
                if(x <= d) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};