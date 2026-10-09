class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniq;

        for (int num : nums)
        {
            uniq.insert(num);
        }

        int maxStreak = 0;
        for (int num : uniq)
        {
            if (uniq.contains(num-1))
            {
                continue;
            }

            int temp = num;
            int streak = 1;
            while (uniq.contains(temp+1))
            {
                streak++;
                temp++;
            }

            maxStreak = max(streak, maxStreak);


        }

        return maxStreak;
    }
};
