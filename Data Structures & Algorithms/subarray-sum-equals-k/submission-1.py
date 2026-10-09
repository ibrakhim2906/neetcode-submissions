class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        cur = 0
        prefix_sum = {0:1}

        for num in nums:
            cur += num
            diff = cur - k

            res += prefix_sum.get(diff, 0)
            prefix_sum[cur] = 1 + prefix_sum.get(cur, 0)

        return res