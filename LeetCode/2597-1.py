class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        group = [[] for _ in range(1000)]
        for elem in nums:
            group[elem % k].append(elem)
        ans = 1
        for i in range(1000):
            lst = group[i]
            lst.sort()
            val = []
            cnt = []
            n = len(lst)
            left = 0
            while left < n:
                right = left + 1
                while right < n and lst[left] == lst[right]:
                    right += 1
                cnt.append(right - left)
                val.append(lst[left])
                left = right
            n = len(cnt)
            dp = [0] * (n + 1)
            dp[0] = 1
            for i in range(n):
                dp[i + 1] = dp[i]
                j = i
                if i != 0 and val[i - 1] == val[i] - k:
                    j = max(0, j - 1)
                dp[i + 1] += ((1 << cnt[i]) - 1) * dp[j]
            ans *= dp[n]
        return ans - 1
