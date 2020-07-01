/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月06日 星期一 11时02分58秒
 ************************************************************************/

class Solution {
    int f[1005][1005];
public:
    int minDistance(string word1, string word2) {
        memset(f, 0x3f3f3f, sizeof(f));
        for(int i = 0; i <= word1.size(); i++) {
            f[i][0] = i;
        }
        for(int i = 0; i <= word2.size(); i++) {
            f[0][i] = i;
        }
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                else {
                    f[i][j] = min(f[i][j], min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1]))) + 1;
                }
            }
        }
        return f[word1.size()][word2.size()];
    }
};

