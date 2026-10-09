class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:

        current_sum=0

        count = 0

        L = 0

        for R in range(len(arr)):
            current_sum+=arr[R]
            if R-L+1==k:
                average = current_sum/k
                if average>=threshold:
                    count+=1
                current_sum-=arr[L]
                L+=1

        return count
            

        
        