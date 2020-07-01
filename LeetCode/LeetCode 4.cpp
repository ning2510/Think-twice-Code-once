/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 17时38分49秒
 ************************************************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0, sum = nums1.size() + nums2.size();
        int flag = 0, mid = sum / 2;
        if(sum & 1) {
            flag = 1;
            mid++;
        }
        int cnt = 0;
        int t1, t2;
        while(l < nums1.size() && r < nums2.size()) {
            cnt++;
            if(nums1[l] <= nums2[r]) {
                if(cnt == mid) t1 = nums1[l];
                if(cnt == mid + 1) t2 = nums1[l];
                l++;
            }
            else {
                if(cnt == mid) t1 = nums2[r];
                if(cnt == mid + 1) t2 = nums2[r];
                r++;
            }
        }
        while(l < nums1.size()) {
            cnt++;
            if(cnt == mid) t1 = nums1[l];
            if(cnt == mid + 1) t2 = nums1[l];
            l++;
        }
        while(r < nums2.size()) {
            cnt++;
            if(cnt == mid) t1 = nums2[r];
            if(cnt == mid + 1) t2 = nums2[r];
            r++;
        }
        double ans = 0.0;
        if(flag) ans = t1;
        else ans = (double)(t1 + t2) / 2.0;
        return ans;
    }
};
