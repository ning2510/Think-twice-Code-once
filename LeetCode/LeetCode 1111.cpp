/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月01日 星期三 16时28分20秒
 ************************************************************************/

// 模拟
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector <int> ss;
        ss.resize(seq.size(), 0);
        int a = 0, b = 0;
        for(int i = 0; i < seq.size(); i++) {
            if(seq[i] == '(') {
                if(a >= b) {
                        ss[i] = 0;
                        a--;
                }
                else {
                    ss[i] = 1;
                    b--;
                }
            }
            else {
                if(a < b) {
                    ss[i] = 0;
                    a++;
                }
                else {
                    ss[i] = 1;
                    b++;
                }
            }
        }
        return ss;
    }
};

// 官方题解: 栈的思想
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};
