class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(!n) return false;
        vector <int> minx(n, 0);
        minx[0] = nums[0];
        for(int i = 1; i < n; i++) {
            minx[i] = min(minx[i - 1], nums[i]); 
        }
        stack <int> ss;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > minx[i]) {
                while(!ss.empty() && ss.top() <= minx[i]) ss.pop();
                while(!ss.empty() && ss.top() < nums[i]) return true;
                ss.push(nums[i]);
            }
        }
        return false;
    }
};