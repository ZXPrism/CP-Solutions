class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        std::ranges::sort(heaters);
        int ans = 0;
        for (auto pos : houses) {
            auto iter = std::ranges::lower_bound(heaters, pos);
            int dist = static_cast<int>(1e9);
            if (iter != heaters.end()) {
                dist = std::min(dist, *iter - pos);
            }
            if (iter != heaters.begin()) {
                dist = std::min(dist, pos - *(--iter));
            }
            ans = std::max(ans, dist);
        }
        return ans;
    }
};
