class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, std::vector<int>, std::greater<int>> maxHeap;

        for (auto num : nums)
        {
            maxHeap.push(num);

            if (maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
        
    }
};
