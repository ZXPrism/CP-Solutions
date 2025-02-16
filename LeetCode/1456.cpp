class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), ans = 0, curr = 0;
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            if (vowels.contains(s[i])) {
                ++curr;
            }
            if (i >= k - 1) {
                ans = std::max(ans, curr);
                if (vowels.contains(s[i - k + 1])) {
                    --curr;
                }
            }
        }
        return ans;
    }
};
