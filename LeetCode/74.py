class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        left, right, mid = -1, m, 0
        while left + 1 < right:
            mid = (left + right) // 2
            if target >= matrix[mid][0]:
                left = mid
            else:
                right = mid
        if left == -1:
            return False
        idx = bisect_left(matrix[left], target)
        if idx != n and matrix[left][idx] == target:
            return True
        else:
            return False
