// 方法一：排序 + 双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int l = 0, r = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(l < nums1.size() && r < nums2.size()) {
            if(nums1[l] == nums2[r]) {
                ans.push_back(nums1[l]);
                l++;
                r++;
            }
            else if(nums1[l] > nums2[r]) {
                r++;
            }
            else l++;
        }
        return ans;
    }
};

// 方法二：哈希表(map)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        unordered_map <int, int> ss;
        for(auto &x : nums1) {
            ss[x]++;
        }
        for(auto &x : nums2) {
            if(ss.count(x) && --ss[x] >= 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
