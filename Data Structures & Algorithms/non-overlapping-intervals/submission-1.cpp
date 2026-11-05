class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        vector<vector<int>> output;

        output.push_back(intervals[0]);

        for (auto& interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = output.back()[1];

            if (start >= lastEnd)
            {
                output.push_back(interval);
            }
        }
        

        return intervals.size()-output.size();
    }
};
