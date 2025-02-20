class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int n = arrays.size(), ans = 0;
        int curr_min = arrays[0].front(), curr_max = arrays[0].back();
        for (int i = 1; i < n; i++) {
            // ans = std::max(ans, std::abs(curr_min - arrays[i].front()));
            ans = std::max(ans, std::abs(curr_max - arrays[i].front()));
            ans = std::max(ans, std::abs(curr_min - arrays[i].back()));
            // ans = std::max(ans, std::abs(curr_max - arrays[i].back()));
            curr_min = std::min(curr_min, arrays[i].front());
            curr_max = std::max(curr_max, arrays[i].back());
        }
        return ans;
    }
};

// 之所以不需要考虑 “最小-最小” 和 “最大-最大”，是因为：
// 假设当前可以取到的最大值为 |x - y|，即 max {x - y, y - x}
// 其中，x 来自当前数组，y 来自之前的数组
// 虽然我们目前不知道这个最大值是多少，但它一定属于这两种情况的其中一种
// 如果是 x - y 的情况，即 x 大于等于 y，那么我们一定可以增大 x，减小 y，使得答案更大——对应
// “最大-最小” 反之，即 x 小于 y，那么我们一定可以减小 x，增大 y，使得答案更大——对应 “最小-最大”
// 所以求出这两种情况的最大值，就能得到总的最大值
// 和今天做过的 ABC100D 是类似的思路
