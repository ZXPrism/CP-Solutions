class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        cnt = [0] * 101
        distinct = 0
        for elem in nums:
            cnt[elem] += 1
            if cnt[elem] == 1:
                distinct += 1
        min_elem = min(nums)
        return distinct if k < min_elem else distinct - 1 if k == min_elem else -1
