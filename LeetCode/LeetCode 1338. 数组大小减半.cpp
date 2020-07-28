class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map <int, int> ss;
        vector <int> pp;
        for(auto &x : arr) ss[x]++;
        for(auto &x : ss) {
            pp.push_back(x.second);
        }
        sort(pp.begin(), pp.end(), [](auto &x, auto &y) {
            return x > y;
        });
        int ans = 0, sum = 0;
        for(auto &x : pp) {
            sum += x;
            ans++;
            if(sum * 2 >= arr.size()) {
                return ans;
            }
        }
        return -1;
    }
};