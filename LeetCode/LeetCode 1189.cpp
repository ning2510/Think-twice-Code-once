/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 18时41分37秒
 ************************************************************************/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int sa = 0, sb = 0, sl = 0, so = 0, sn = 0;
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == 'a') sa++;
            if(text[i] == 'b') sb++;
            if(text[i] == 'l') sl++;
            if(text[i] == 'o') so++;
            if(text[i] == 'n') sn++;
        }
        sl /= 2;
        so /= 2;
        int ans = min(sa, min(sb, min(sl, min(so, sn))));
        return ans;
    }
};
