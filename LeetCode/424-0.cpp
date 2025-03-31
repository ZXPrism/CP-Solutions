class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        std::vector<std::vector<int>> group(26);
        for (int i = 0; i < n; i++) {
            group[s[i] - 'A'].push_back(i);
        }
        for (auto &pos : group) {
            int n_pos = pos.size();
            for (int left = 0, right = 0; right < n_pos; right++) {
                while ((pos[right] - pos[left]) - (right - left) > k) {
                    ++left;
                }
                int len = pos[right] - pos[left] + 1;
                int used = len - (right - left + 1);
                int extra = std::min(k - used, pos[left] + n - 1 - pos[right]);
                ans = std::max(ans, len + extra);
            }
        }
        return ans;
    }
};
