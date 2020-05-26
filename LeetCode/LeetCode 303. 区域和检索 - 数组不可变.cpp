class NumArray {
public:
    vector <int> ss;

    NumArray(vector<int>& nums) {
        ss.resize(nums.size() + 5, 0);
        for(int i = 0; i < nums.size(); i++) {
            ss[i + 1] = ss[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return ss[j + 1] - ss[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */