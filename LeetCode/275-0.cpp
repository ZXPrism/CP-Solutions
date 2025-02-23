class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        auto check = [&](int h) -> bool {
            return citations.end() - std::ranges::lower_bound(citations, h) >= h;
        };
        int left = -1, right = 1001, mid = 0;
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
