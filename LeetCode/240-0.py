class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            t = bisect_left(matrix[i], target)
            if t != n and matrix[i][t] == target:
                return True
        return False
