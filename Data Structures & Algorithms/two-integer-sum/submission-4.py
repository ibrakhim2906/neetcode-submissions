class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        num_map = {}

        for i in range(len(nums)):
            num_map[nums[i]] = i

        for i in range(len(nums)):
            need_num = target-nums[i]
            
            if need_num in num_map and num_map[need_num]!=i:
                return [i, num_map[need_num]]

        