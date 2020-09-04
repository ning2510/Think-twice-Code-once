class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int, int> ss;
        for(auto &x : arr) {
            if(ss.count(x * 2)) return true;
            if(!(x & 1)) {
                if(ss.count(x / 2)) return true;
            }
            ss[x] = 1;
        }
        return false;
    }
};