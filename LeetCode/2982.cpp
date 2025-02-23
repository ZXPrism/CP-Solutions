class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        std::vector<std::vector<int>> cnt(26);
        for (int left = 0; left < n;) {
            int right = left + 1;
            while (right < n && s[left] == s[right]) {
                ++right;
            }
            cnt[s[left] - 'a'].push_back(right - left);
            left = right;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (!cnt[i].empty()) {
                int left = 0, right = *std::ranges::max_element(cnt[i]) + 1, mid = 0;

                auto check = [&](int len) -> bool {
                    int tot = 0;
                    for (auto x : cnt[i]) {
                        tot += std::max(0, x - len + 1);
                    }
                    return tot >= 3;
                };

                while (left + 1 < right) {
                    mid = (left + right) / 2;
                    if (check(mid)) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                ans = std::max(ans, left);
            }
        }

        return (!ans ? -1 : ans);
    }
};
