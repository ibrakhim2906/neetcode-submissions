class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int l = 0;
        int r = 0;

        int maxSub = 0;
        unordered_set<char> seen{};
        while (r < s.size())
        {
            while(seen.count(s[r]))
            {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            maxSub = max(maxSub, r-l+1);
            r++;
        }

        return maxSub;
    }
};
