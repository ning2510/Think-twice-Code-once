class Solution {
public:
    int exchangeBits(int num) {
        vector <int> ss;
        while(num) {
            ss.push_back(num & 1);
            num >>= 1;
        }
        int ans = 0;
        for(int i = 0; i < ss.size(); i += 2) {
            if(i + 1 < ss.size()) {
                swap(ss[i], ss[i + 1]);
                if(ss[i]) ans |= (1 << i);
                if(ss[i + 1]) ans |= (1 << (i + 1));
            }
            else {
                if(ss[i]) ans |= (1 << (i + 1));
            }
        }
        return ans;
    }
};