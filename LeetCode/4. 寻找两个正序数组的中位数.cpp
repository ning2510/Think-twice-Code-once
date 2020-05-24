class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = 0;
        vector <int> ss;
        while(l < n && r < m) {
            if(nums1[l] < nums2[r]) ss.push_back(nums1[l++]);
            else ss.push_back(nums2[r++]);
        }
        while(l < n) ss.push_back(nums1[l++]);
        while(r < m) ss.push_back(nums2[r++]);
        int x = (n + m) / 2;
        if((n + m) & 1) return ss[x];
        else return ((double)(ss[x] + ss[x - 1]) / 2);
    }
};