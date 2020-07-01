class Solution {
    vector <int> ss;

    int dfs(int x, int label) {
        if(x > label) return 0;
        if(x == label) {
            ss.push_back(x);
            return 1;
        }
        if(dfs(x << 1, label)) {
            ss.push_back(x);
            return 1;
        }
        if(dfs(x << 1 | 1, label)) {
            ss.push_back(x);
            return 1;
        }
        return 0;
    }

public:
    vector<int> pathInZigZagTree(int label) {
        int x = 1, cnt = 1;
        while(x <= label) { //计算label在第几层，从第１层开始算
            cnt++;
            x <<= 1;
        }
        cnt -= 2;   //从第0层开始算是第几层
        if(cnt & 1) {   //如果是奇数，说明要查找的数字应该是通过中心对称的到的数，例：label=14,则我们要查找顺序二叉树中的９
            x = x / 2 + x - 1;
            label = x - label;
        }
        //cout << cnt << ' ' << label << endl;
        dfs(1, label);
        reverse(ss.begin(), ss.end());
        /*for(int i = 0; i < ss.size(); i++) {
            cout << ss[i] << ' ';
        }
        cout << endl;*/
        for(int i = 0; i < ss.size(); i++) {
            if(i & 1) { //若是奇数层，那么ss中的数应是与这个数中心对称的数
                x = pow(2, i) + pow(2, i + 1) - 1;
                //cout << i << ' ' << x << endl;
                ss[i] = x - ss[i];
            }
        }
        return ss;
    }
};