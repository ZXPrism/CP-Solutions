class Solution {
public:
    int similarPairs(vector<string> &words) {
        int n = words.size(), ans = 0;
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int state = 0;
            for (auto ch : words[i]) {
                state |= 1 << (ch - 'a');
            }
            ans += cnt[state]++;
        }
        return ans;
    }
};
