class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)

        def check(val: int) -> bool:
            cnt = 0
            for i in range(n):
                cnt += bisect_right(matrix[i], val)
            return cnt >= k

        left = int(-1e9) - 1
        right = int(1e9) + 1
        mid = 0
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid

        return right
