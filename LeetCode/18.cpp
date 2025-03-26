class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        std::ranges::sort(nums);

        std::vector<std::vector<int>> ans;
        int n = nums.size();

        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                int add = nums[i] + nums[j];

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = add + 1LL * nums[left] + nums[right];
                    if (sum > target) {
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int a = nums[left];
                        while (left < right && nums[left] == a) {
                            ++left;
                        }
                        int b = nums[right];
                        while (left < right && nums[right] == b) {
                            --right;
                        }
                    }
                }

                int val = nums[j];
                while (j < n && nums[j] == val) {
                    ++j;
                }
            }

            int val = nums[i];
            while (i < n && nums[i] == val) {
                ++i;
            }
        }

        return ans;
    }
};
