class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        long long ans = 0;
        int n = rectangles.size();
        std::unordered_map<long long, int> cnt;
        for (int i = 0; i < n; i++) {
            int fac = std::gcd(rectangles[i][0], rectangles[i][1]);
            long long eigen = ((1LL * rectangles[i][0] / fac) << 32) + rectangles[i][1] / fac;
            ans += cnt[eigen]++;
        }
        return ans;
    }
};
