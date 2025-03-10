class Solution:
    def findMaxSum(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        n = len(nums1)

        idx = [i for i in range(n)]
        idx.sort(key=lambda x: nums1[x])

        ans = [0] * n
        heap = []
        curr = 0
        left = 0
        while left < n:
            right = left + 1
            while right < n and nums1[idx[left]] == nums1[idx[right]]:
                right += 1

            for i in range(left, right):
                ans[idx[i]] = curr

            for i in range(left, right):
                if len(heap) < k:
                    heappush(heap, nums2[idx[i]])
                    curr += nums2[idx[i]]
                elif heap[0] < nums2[idx[i]]:
                    out = heappushpop(heap, nums2[idx[i]])
                    curr += -out + nums2[idx[i]]

            left = right

        return ans
