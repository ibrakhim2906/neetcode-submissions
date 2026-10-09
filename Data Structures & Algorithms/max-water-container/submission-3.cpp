class Solution {
public:

    int calculateArea(int height, int width)
    {
        return height*width;
    }

    int maxArea(vector<int>& heights) {

        int n = heights.size();
        int l = 0, r = n-1;

        int maxArea = 0;
        while (l<r)
        {
            int curArea = calculateArea(min(heights[l], heights[r]), (r-l));
            
            maxArea = max(maxArea, curArea);

            if (heights[l] <= heights[r])
            {
                l++;
            } else {
                r--;
            }
        }

        return maxArea;
        
    }
};
