class Solution {
    vector <int> ss;
    vector <int> copy;

public:
    Solution(vector<int>& nums) {
        ss = nums;
        copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ss = copy;
        return ss;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = ss.size() - 1; i >= 0; i--) {
            int x = rand() % (i + 1);
            swap(ss[x], ss[i]);
        }
        return ss;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */