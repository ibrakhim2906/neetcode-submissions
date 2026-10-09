class KthLargest {

public:
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int k;
    KthLargest(int k, vector<int>& nums) : k{k} {

        for (int i : nums)
        {
            minHeap.push(i);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        
        
    }
    
    int add(int val) {

        minHeap.push(val);
        
        if (minHeap.size()>k)
        {
            minHeap.pop();
        }

        return minHeap.top();
        
    }
};
