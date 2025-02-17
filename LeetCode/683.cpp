class Solution {
public:
    int kEmptySlots(vector<int> &bulbs, int k) {
        int n = bulbs.size(), ans = n + 1;
        std::vector<int> day(n);
        for (int i = 0; i < n; i++) {
            day[bulbs[i] - 1] = i + 1;
        }

        if (k == 0) {
            for (int i = 0; i < n - 1; i++) {
                ans = std::min(ans, std::max(day[i], day[i + 1]));
            }
            return ans;
        }

        std::deque<int> minQueue;
        for (int i = 0; i < n - 1; i++) {
            while (!minQueue.empty() && day[i] <= day[minQueue.back()]) {
                minQueue.pop_back();
            }
            minQueue.push_back(i);
            if (i >= k - 1) {
                while (!minQueue.empty() && minQueue.front() < i - k + 1) {
                    minQueue.pop_front();
                }

                if (i >= k) {
                    int curr = std::max(day[i - k], day[i + 1]);
                    if (day[minQueue.front()] > curr) {
                        ans = std::min(ans, curr);
                    }
                }
            }
        }

        return (ans == n + 1 ? -1 : ans);
    }
};
