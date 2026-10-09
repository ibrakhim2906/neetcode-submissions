class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        k=1
        L = 0
        for R in range(1,len(nums)):
            if nums[L]!=nums[R]:
                L+=1
                nums[L]=nums[R]
                k+=1
            else:
                pass

        return k
