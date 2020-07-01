/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月27日 星期五 17时11分46秒
 ************************************************************************/

class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() <= 1) return false;
        map <int, int> ss;
        for(int i = 0; i < deck.size(); i++) {
            ss[deck[i]]++;
        }
        map <int, int> :: iterator it = ss.begin();
        int vis = 0;
        int a = it->second;
        it++;
        for(; it != ss.end(); it++) {
            int b = it->second;
            int x = gcd(a, b);
            if(x < 2) return false;
            a = b;
        }
        return true;
    }
};
