class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        ans = [-1, -1]
        for i in range(m):
            cnt = 0
            for elem in mat[i]:
                if elem == 1:
                    cnt += 1
            if cnt > ans[1]:
                ans[1] = cnt
                ans[0] = i
        return ans
