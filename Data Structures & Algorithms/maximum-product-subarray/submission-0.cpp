class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans = nums[0];
        int mx = nums[0];
        int mn = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int x = nums[i];
            int a = mx;
            int b = mn;

            mx = max({x, a*x, b*x});
            mn = min({x, a*x, b*x});

            ans = max(ans, mx);

            
        }

        return ans;

        
    }
};
