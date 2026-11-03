class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxval = nums[0];

        int cur =0;
        for (int i = 0 ; i < nums.size(); i++)
        {

            if (cur < 0)
            {
                cur = 0;
            }

            cur += nums[i];

            maxval = max(maxval, cur);

        }

        return maxval;

    }
};
