class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);

        stack<int> stck;

        for (int i = 0; i<n; i++)
        {
            while (!stck.empty() && 
            heights[stck.top()]>=heights[i])
            {
                stck.pop();
            }

            if (!stck.empty())
            {
                leftMost[i] = stck.top();
            }

            stck.push(i);
        }

        while (!stck.empty())
        {
            stck.pop();
        }
        for (int i = n-1; i>=0; i--)
        {
            while (!stck.empty() && 
            heights[stck.top()] >= heights[i])
            {
                stck.pop();
            }

            if (!stck.empty())
            {
                rightMost[i] = stck.top();
            }

            stck.push(i);

        }

        int maxArea = 0;
        
        for (int i = 0; i < n; i++)
        {
            leftMost[i] +=1;
            rightMost[i] -=1;
            maxArea = max(maxArea, heights[i]*(rightMost[i]-leftMost[i]+1));
        }

        return maxArea;
        
        

    }
};
