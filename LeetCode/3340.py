class Solution:
    def isBalanced(self, num: str) -> bool:
        n = len(num)
        s, s1 = 0, 0
        for i in range(n):
            s += ord(num[i]) - 48
            if i % 2 == 0:
                s1 += ord(num[i]) - 48
        return s - s1 == s1
