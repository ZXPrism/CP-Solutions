class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int n = s.size(), ans = 0;
        for (int i = 1; i <= 26 && i * count <= n; i++) {
            int len = i * count;
            std::vector<int> cnt(26);
            for (int j = 0; j < n; j++) {
                ++cnt[s[j] - 'a'];
                if (j >= len - 1) {
                    bool flag = true;
                    for (int k = 0; k < 26; k++) {
                        if (cnt[k] && cnt[k] != count) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ++ans;
                    }
                    --cnt[s[j - len + 1] - 'a'];
                }
            }
        }
        return ans;
    }
};
