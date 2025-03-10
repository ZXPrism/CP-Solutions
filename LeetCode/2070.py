# daily for 2025-03-09


class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort(key=lambda x: x[0])
        n = len(items)
        pre_max = [0] * (n + 1)
        for i in range(n):
            pre_max[i + 1] = max(pre_max[i], items[i][1])

        ans = []
        for q in queries:
            left, right, mid = -1, n, 0
            while left + 1 < right:
                mid = (left + right) // 2
                if items[mid][0] <= q:
                    left = mid
                else:
                    right = mid
            ans.append(pre_max[left + 1])

        return ans
