class Solution {
public:
    int largestVariance(string s) {
        constexpr int INF = std::numeric_limits<int>::max();
        int ans = 0, n = s.size();
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                if (a == b) {
                    continue;
                }
                int f0 = 0, f1 = -INF;
                for (int i = 0; i < n; i++) {
                    if (s[i] == a) {
                        f0 = std::max(f0, 0) + 1;
                        ++f1;
                    } else if (s[i] == b) {
                        f0 = std::max(f0, 0) - 1;
                        f1 = f0;
                    }
                    ans = std::max(ans, f1);
                }
            }
        }
        return ans;
    }
};
