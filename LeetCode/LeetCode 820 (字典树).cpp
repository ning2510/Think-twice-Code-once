/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 21时17分56秒
 ************************************************************************/

/* 字典树 136ms
*
* 大致说一下此题的思想,将每个单词倒着在字典树中查找,记录最长的单词,把所有最长的单词相加就是我们所有,当然记得加上 # 分隔符
* 这时有两种情况: 1.没有这个字母  则把这个字母存进去
*                 2.有这个字母 直接遍历下一位
* 每个节点有个变量 count, count为1说明此节点不是一个完整的单词,即还要再向下遍历
* 若count为0,说明此单词为我们所求的单词中其中一个单词的首字母
*/
class TrieNode{
    TrieNode* children[26];
public:
    int count;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = NULL;
        count = 0;
    }
    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;  //这里的count++,只代表 this->count 加了1,而children[c-'a']->conut为0
            //cout << "@@@  " << children[c - 'a']->count << endl;
        }
        return children[c - 'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur->get(word[j]);
            nodes[cur] = i;
            //cout << word << ' ' << cur->count << ' ' << cur << endl;
        }

        int ans = 0;
        for (auto& [node, idx] : nodes) {
            //cout << node->count << ' ' << words[idx] << endl;
            if (node->count == 0) {
                ans += words[idx].length() + 1;
            }
        }
        return ans;
    }
};

// 偏暴力 100ms
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> ss(words.begin(), words.end());       
        for(auto &s : ss) {
            for(int i = 1; i < s.size(); i++) {
                ss.erase(s.substr(i));
            }
        }
        int ans = 0;
        for(auto &s : ss) {
            ans += s.size() + 1;
            cout << s << ' ' << s.size() + 1 << endl;
        }
        return ans;
    }
};

