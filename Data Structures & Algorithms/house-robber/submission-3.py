class Solution:
    def rob(self, nums: List[int]) -> int:
        
        def dp_top_down(nums: list[int], i, cache):
            if i<0:
                return 0
            if i in cache:
                return cache[i]

            cache[i] = max(nums[i] + dp_top_down(nums, i-2, cache), dp_top_down(nums, i-1, cache))

            return cache[i]

        return dp_top_down(nums, len(nums)-1, {})