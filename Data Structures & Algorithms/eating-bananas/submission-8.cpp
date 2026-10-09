class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int k = r;

        while (l <= r)
        {
            int m = l+(r-l)/2;

            long long time = 0;

            for (int pile : piles)
            {
                time += (pile + m - 1LL) / m;
            }
            
            if (time <= h)
            {
                k = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return k;
    }
};
