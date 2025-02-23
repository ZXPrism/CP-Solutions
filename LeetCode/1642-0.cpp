class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int n = heights.size();
        auto check = [&](int mid) -> bool {
            int bricks_copy = bricks, ladders_copy = ladders;
            std::priority_queue<int, std::vector<int>, std::greater<>> q;
            for (int i = 1; i <= mid; i++) {
                if (heights[i - 1] < heights[i]) {
                    q.push(heights[i] - heights[i - 1]);
                }
            }
            while (!q.empty()) {
                if (bricks_copy >= q.top()) {
                    bricks_copy -= q.top();
                } else if (ladders_copy) {
                    --ladders_copy;
                } else {
                    return false;
                }
                q.pop();
            }
            return true;
        };
        int left = 0, right = n, mid = 0;
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
