//方法一：二分
class Solution {
public:
    int Binary_search(int l, int r, string s, vector<string>& words) {
        if(l > r) return 0;
        int mid = (l + r) >> 1;
        if(words[mid] == s) return mid;
        else if(words[mid] == "") return Binary_search(l, mid - 1, s, words) | Binary_search(mid + 1, r, s, words);
        else if(words[mid] > s) return Binary_search(l, mid - 1, s, words);
        return Binary_search(mid + 1, r, s, words);
    }

    int findString(vector<string>& words, string s) {
        int x = Binary_search(0, words.size() - 1, s, words);
        return x ? x : (words[0] == s ? 0 : -1);
    }
};

//方法二：自带的find，本质也是二分
class Solution {
public:
    int findString(vector<string>& words, string s) {
        auto it = find(words.begin(), words.end(), s);
        if (it != words.end()) return it - words.begin();
        else return -1;
    }
};
