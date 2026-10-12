from typing import List

class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int],k1: int, k2:int) -> int:
        n = len(nums1)

        k = k1 + k2
        diffs = [abs(nums1[i] - nums2[i]) for i in range(n)]
        sum_diff = sum(diffs)
        if k >= sum_diff:
            return 0

        max_diff = max(diffs)

        bucket = [0] * (max_diff + 1)
        for diff in diffs:
            bucket[diff] += 1

        for d in range(max_diff, 0, -1):
            if bucket[d] > 0:
                if k == 0:
                    break

                reduce_count = min(bucket[d], k)
                bucket[d] -= reduce_count
                bucket[d - 1] += reduce_count
                k -= reduce_count

        answer = 0
        for d in range(1, max_diff + 1):
            if bucket[d] > 0:
                answer += bucket[d] * (d * d)

        return answer

        