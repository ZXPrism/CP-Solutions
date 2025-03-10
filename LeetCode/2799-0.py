class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = [0] * 2001
        unique = 0
        for elem in nums:
            cnt[elem] += 1
            if cnt[elem] == 1:
                unique += 1

        cnt = [0] * 2001
        left, ans1 = 0, 0
        distinct = 0
        for right, elem in enumerate(nums):
            cnt[elem] += 1
            if cnt[elem] == 1:
                distinct += 1
            while distinct >= unique:
                cnt[nums[left]] -= 1
                if cnt[nums[left]] == 0:
                    distinct -= 1
                left += 1
            ans1 += left

        cnt = [0] * 2001
        left, ans2 = 0, 0
        distinct = 0
        for right, elem in enumerate(nums):
            cnt[elem] += 1
            if cnt[elem] == 1:
                distinct += 1
            while distinct > unique:
                cnt[nums[left]] -= 1
                if cnt[nums[left]] == 0:
                    distinct -= 1
                left += 1
            ans2 += left

        return ans1 - ans2
