class Solution {
public:
    int search(vector<int>& nums, int target) {

        // [3, 4, 5, 6, 1, 2]
        // l = 0, r = 5, m = 2
        // nums[l] = 3
        // nums[r] = 2
        // nums[m] = 5

        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int m = l + (r-l)/2;

            if (target == nums[m])
            {
                return m;
            }
            if (nums[m] <= nums[r])
            {
                if (nums[m] <= target && target <= nums[r])
                {
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else
            {
                if (nums[l] <= target && target <= nums[m])
                {
                    r = m-1;
                } else{
                    l = m+1;
                }
            }
        }

        return -1;
        
    }
};
