class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int, int> sum, end;
        for(auto &x : nums) sum[x]++;
        for(auto &x : nums) {
            if(!sum[x]) continue;
            else if(sum[x] && end[x - 1]) {
                sum[x]--;
                end[x - 1]--;
                end[x]++;
            }
            else if(sum[x] && sum[x + 1] && sum[x + 2]) {
                sum[x]--;
                sum[x + 1]--;
                sum[x + 2]--;
                end[x + 2]++;
            }
            else return false;
        }
        return true;
    }
};