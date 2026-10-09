class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count(26, 0);

        for (char ch : s1)
        {
            int idx = static_cast<int>(ch) - 97;

            count[idx]++;
        }

        int l = 0, r = s1.size();

        while (r <= s2.size())
        {
            vector<int> count2(26,0);

            for (int i = l; i < r; i++)
            {
                int idx = static_cast<int>(s2[i]) - 97;
                count2[idx]++;
            }

            bool good = true;
            for (int i = 0; i < 26; i++)
            {
                if (count[i] != count2[i])
                {
                    good = false;
                }
            }

            if (good)
            {
                return true;
            }

            l++;
            r++;
        }

        return false;
    }
};