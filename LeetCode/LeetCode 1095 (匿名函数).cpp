/*************************************************************************
	> File Name: bbb.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 23时42分49秒
 ************************************************************************/

/**
 *  * // This is the MountainArray's API interface.
 *   * // You should not implement it, or speculate about its implementation
 *    * class MountainArray {
 *     *   public:
 *      *     int get(int index);
 *       *     int length();
 *        * };
 *         */

//先找峰顶 然后进行左右两次二分
class Solution {
    int binary_search(MountainArray mountainArr, int target, int l, int r, int key(int)) {
        target = key(target);
        while(l <= r) {
            int mid = (l + r) >> 1;
            int x = key(mountainArr.get(mid));
            if(x == target) return mid;
            if(x < target) l = mid + 1;
            else r = mid - 1;
                     
        }
        return -1;
             
    }

    public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        if(!r) return -1;
        int ans = 0x3f3f3f;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(mountainArr.get(mid) >= mountainArr.get(mid + 1)) r = mid;
            else l = mid + 1;         
        }
        r = mountainArr.length() - 1;
        int t = binary_search(mountainArr, target, 0, l, [](int x) -> int{return x;});
        //这里运用匿名函数，使得两次查找可以共用一个函数，主要是省事。。。
        if(t != -1) return t;
        else return binary_search(mountainArr, target, l + 1, r, [](int x) -> int{return -x;});     
     }

 };

