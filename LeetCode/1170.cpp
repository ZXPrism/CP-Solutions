class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        auto F = [](const std::string &s) -> int {
            std::vector<int> cnt(26);
            for (auto ch : s) {
                ++cnt[ch - 'a'];
            }
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    return cnt[i];
                }
            }
            return -1;
        };

        int n = words.size();
        std::vector<int> f_array(n);
        for (int i = 0; i < n; i++) {
            f_array[i] = F(words[i]);
        }
        std::ranges::sort(f_array);

        int q = queries.size();
        std::vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int target = F(queries[i]);
            ans[i] = n - (std::ranges::upper_bound(f_array, target) - f_array.begin());
        }

        return ans;
    }
};
