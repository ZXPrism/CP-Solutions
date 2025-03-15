class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        left, ans = 0, 0
        cnt_pair = 0
        cnt = Counter()
        for right, elem in enumerate(nums):
            cnt_pair += cnt[elem]
            cnt[elem] += 1
            while cnt_pair >= k:
                cnt_pair -= cnt[nums[left]] - 1
                cnt[nums[left]] -= 1
                left += 1
            ans += left
        return ans
