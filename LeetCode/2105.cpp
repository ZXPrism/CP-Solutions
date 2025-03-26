class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int ans = 0;
        int left = 0, right = plants.size() - 1;
        int alice = capacityA, bob = capacityB;
        while (left < right) {
            if (alice >= plants[left]) {
                alice -= plants[left];
            } else {
                ++ans;
                alice = capacityA - plants[left];
            }
            if (bob >= plants[right]) {
                bob -= plants[right];
            } else {
                ++ans;
                bob = capacityB - plants[right];
            }
            ++left;
            --right;
        }
        if (left == right) {
            if (alice >= bob) {
                if (alice < plants[left]) {
                    ++ans;
                }
            } else {
                if (bob < plants[left]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
