class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector <string> ans;
        vector <int> minx(26, INT_MAX);
        vector <int> sum(26, 0);
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                int t = A[i][j] - 'a';
                sum[t]++;
            }
            for(int j = 0; j < 26; j++) {
                minx[j] = min(minx[j], sum[j]);
                sum[j] = 0;
            }
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j <= minx[i]; j++) {
                ans.emplace_back(1, i + 'a');   
                //相当于 ans.push_back(string(1, i + 'a'));
                //stirng(1, i + 'a'):stirng类型的构造函数，第一个参数表示要构造的字符串长度是1
            }
        }
        return ans;
    }
};