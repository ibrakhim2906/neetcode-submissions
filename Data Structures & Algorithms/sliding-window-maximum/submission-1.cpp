class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);
        deque<int> window;

        int l = 0, r = 0;

        while (r < n) {
            while (!window.empty() && nums[window.back()] < nums[r]) {
                window.pop_back();
            }
            window.push_back(r);

            if (l > window.front()) {
                window.pop_front();
            }

            if ((r + 1) >= k) {
                output[l] = nums[window.front()];
                l++;
            }

            r++;
        }

        return output;
    }
};
