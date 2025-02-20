class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        std::vector<int> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i] = std::abs(arr[i] - x);
        }

        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::ranges::sort(idx, [&](int lhs, int rhs) {
            return (dist[lhs] == dist[rhs] ? arr[lhs] < arr[rhs] : dist[lhs] < dist[rhs]);
        });

        std::vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = arr[idx[i]];
        }
        std::ranges::sort(ans);

        return ans;
    }
};
