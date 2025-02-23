class Solution {
public:
    int maximumRemovals(string s, string p, vector<int> &removable) {
        int n = s.size(), m = p.size();

        std::vector<int> remove(n, n);
        for (int i = 0; i < removable.size(); i++) {
            remove[removable[i]] = i;
        }

        auto check = [&](int k) -> bool {
            int match = 0;
            for (int i = 0; i < n; i++) {
                if (remove[i] < k) {
                    continue;
                }
                if (match < m && s[i] == p[match]) {
                    ++match;
                }
            }
            return match == m;
        };

        int left = -1, right = removable.size() + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
