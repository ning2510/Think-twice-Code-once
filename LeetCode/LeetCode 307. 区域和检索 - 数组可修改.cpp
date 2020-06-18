class NumArray {
public:
    int n;
    vector <int> ss;
    vector <int> c;

    int lowbit(int x) {
        return x & (-x);
    }

    void Tree_update(int i, int x) {
        while(i <= n) {
            c[i] += x;
            i += lowbit(i);
        }
        return ;
    }

    int get_sum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        c.resize(n + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            ss.push_back(nums[i]);
            Tree_update(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        Tree_update(i + 1, val - ss[i]);
        ss[i] = val;
    }
    
    int sumRange(int i, int j) {
        return get_sum(j + 1) - get_sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */