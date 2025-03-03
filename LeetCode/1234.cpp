class Solution {
public:
    int balancedString(string s) {
        int n = s.size();

        std::vector<int> cnt(128);
        for (auto ch : s) {
            ++cnt[ch];
        }
        if (cnt['Q'] == n / 4 && cnt['W'] == n / 4 && cnt['E'] == n / 4) {
            return 0;
        }

        auto check = [&](int len) -> bool {
            int diff = 0;
            for (auto ch : {'Q', 'W', 'E', 'R'}) {
                if (cnt[ch] > n / 4) {
                    return false;
                }
                diff += n / 4 - cnt[ch];
            }
            return diff == len;
        };

        int ans = n;
        for (int left = 0, right = 0; right < n; right++) {
            --cnt[s[right]];
            while (check(right - left + 1)) {
                ans = std::min(ans, right - left + 1);
                ++cnt[s[left++]];
            }
        }

        return ans;
    }
};
