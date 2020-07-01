class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }
        int s1cnt = 0, index = 0, s2cnt = 0;
        // recall ������������ѭ���ڵı���������һ����ϣӳ��
        // ���������ѭ���ڣ��������Ǳ����� s1cnt �� s1����ʱƥ�䵽�˵� s2cnt �� s2 �еĵ� index ���ַ�
        // �������֮ǰ������ s1cnt' �� s1 ʱ��ƥ�䵽���ǵ� s2cnt' �� s2 ��ͬ���ĵ� index ���ַ�����ô����ѭ������
        // ������ (s1cnt', s2cnt', index) �� (s1cnt, s2cnt, index) ��ʾ���ΰ�����ͬ index ��ƥ����
        // ��ô��ϣӳ���еļ����� index��ֵ���� (s1cnt', s2cnt') �����Ԫ��
        // ѭ���ھ��ǣ�
        //    - ǰ s1cnt' �� s1 ������ s2cnt' �� s2
        //    - �Ժ��ÿ (s1cnt - s1cnt') �� s1 ������ (s2cnt - s2cnt') �� s2
        // ��ô����ʣ�� (n1 - s1cnt') % (s1cnt - s1cnt') �� s1, ���Ƕ���Щ�� s2 ���б���ƥ��
        // ע�� s2 Ҫ�ӵ� index ���ַ���ʼƥ��
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            // ���Ƕ����һ�� s1�������ܲ����ҵ�ѭ����
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index += 1;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            // ��û���ҵ�ѭ���ڣ����е� s1 ��������
            if (s1cnt == n1) {
                return s2cnt / n2;
            }
            // ������֮ǰ�� index����ʾ�ҵ���ѭ����
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // ǰ s1cnt' �� s1 ������ s2cnt' �� s2
                pre_loop = {s1cnt_prime, s2cnt_prime};
                // �Ժ��ÿ (s1cnt - s1cnt') �� s1 ������ (s2cnt - s2cnt') �� s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            }
            else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        // ans �洢���� S1 ������ s2 �����������ǵ�֮ǰ�� pre_loop �� in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 ��ĩβ��ʣ��һЩ s1�����Ǳ�������ƥ��
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (char ch: s1) {
                if (ch == s2[index]) {
                    ++index;
                    if (index == s2.size()) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }
        // S1 ���� ans �� s2����ô�Ͱ��� ans / n2 �� S2
        return ans / n2;
    }
};
