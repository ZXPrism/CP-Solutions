class Solution {
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
        int n = nums.size();
        std::vector<std::vector<int>> idx(*std::ranges::max_element(nums) + 1);
        for (int i = 0; i < n; i++) {
            idx[nums[i]].push_back(i);
        }

        int q = queries.size();
        std::vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int query = queries[i];
            auto &vec = idx[nums[query]];
            if (vec.size() == 1) {
                ans[i] = -1;
            } else {
                int x = std::ranges::lower_bound(vec, query) - vec.begin();
                int min_dist = n;
                if (x != 0) {
                    min_dist = std::min(min_dist, vec[x] - vec[x - 1]);
                }
                if (x != vec.size() - 1) {
                    min_dist = std::min(min_dist, vec[x + 1] - vec[x]);
                }
                if (x == 0 || x == vec.size() - 1) {
                    min_dist = std::min(min_dist, n + vec.front() - vec.back());
                }
                ans[i] = min_dist;
            }
        }

        return ans;
    }
};
