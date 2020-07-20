class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> ss;
        for(int i = 0; i < numbers.size(); i++) {
            if(ss.count(target - numbers[i])) {
                return {ss[target - numbers[i]] + 1, i + 1};
            }
            ss[numbers[i]] = i;
        }
        return {-1, -1};
    }
};