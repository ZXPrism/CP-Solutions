class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        int n = words.size(), q = puzzles.size();

        std::unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int eigen = 0;
            for (auto ch : words[i]) {
                eigen |= 1 << (ch - 'a');
            }
            if (__builtin_popcount(eigen) <= 7) {
                ++cnt[eigen];
            }
        }

        std::vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int mask = 0;
            for (int j = 1; j < 7; j++) {
                mask |= 1 << (puzzles[i][j] - 'a');
            }
            int target = mask;
            while (target) {
                ans[i] += cnt[target | (1 << (puzzles[i][0] - 'a'))];
                target = (target - 1) & mask;
            }
            ans[i] += cnt[1 << (puzzles[i][0] - 'a')];
        }

        return ans;
    }
};
