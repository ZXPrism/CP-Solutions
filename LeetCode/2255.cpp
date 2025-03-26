class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        int cnt = 0;
        for (auto &str : words) {
            cnt += (s.find(str) == 0);
        }
        return cnt;
    }
};
