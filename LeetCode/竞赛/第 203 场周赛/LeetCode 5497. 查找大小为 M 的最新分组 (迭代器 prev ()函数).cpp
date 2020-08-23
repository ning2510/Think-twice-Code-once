class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(n == m) return n;
        map<int, int> s = {{1, n}};
        for(int i = n - 1; i >= 0; --i) {
            //s.upper_bound(arr[i]):获取指向s键中第一大于arr[i]的迭代器
            //prev(s.upper_bound(arr[i])):令该迭代器向前移动一位
            //prev(it, 1) <==> prev(it)
            //prev(it, 2): 向前移动两位
            auto it = prev(s.upper_bound(arr[i]));
            auto [l, r] = *it;
            if(arr[i] - l == m || r - arr[i] == m) {
                return i;
            }
            s.erase(it);
            if(l <= arr[i] - 1) s.emplace(l, arr[i] - 1);
            if(arr[i] + 1 <= r) s.emplace(arr[i] + 1, r);
        }
        return -1;
    }
};