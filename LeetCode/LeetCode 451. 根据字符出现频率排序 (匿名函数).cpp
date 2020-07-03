class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> ss;
        for(auto &x : s) ss[x]++;
        //[&]:用到的任何外部变量都隐式按引用捕获
        sort(s.begin(), s.end(), [&](auto &x, auto &y) {
            return ss[x] > ss[y] || (ss[x] == ss[y] && x < y);
        });
        return s;
    }
};