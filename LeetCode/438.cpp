class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // almost identical with LC567
        auto &s1 = p, &s2 = s;

        int n1 = s1.size(), n2 = s2.size();

        std::vector<int> pattern(26);
        for (auto ch : s1) {
            ++pattern[ch - 'a'];
        }

        int req = n1;
        std::vector<int> cnt(26), ans;
        for (int i = 0; i < n2; i++) {
            ++cnt[s2[i] - 'a'];
            if (cnt[s2[i] - 'a'] <= pattern[s2[i] - 'a']) {
                --req;
            } else {
                ++req;
            }
            if (i >= n1 - 1) {
                if (req == 0) {
                    ans.push_back(i - n1 + 1);
                }
                --cnt[s2[i - n1 + 1] - 'a'];
                if (cnt[s2[i - n1 + 1] - 'a'] < pattern[s2[i - n1 + 1] - 'a']) {
                    ++req;
                } else {
                    --req;
                }
            }
        }

        return ans;
    }
};
