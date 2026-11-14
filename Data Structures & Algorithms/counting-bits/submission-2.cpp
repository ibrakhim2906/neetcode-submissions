class Solution {
public:

    int count(int n)
    {
        int res = 0;

        for (int i = 0; i < 16; i++)
        {
            if ((1<<i) & n)
            {
                res++;
            }
        }

        return res;
    }
    vector<int> countBits(int n) {

        vector<int> result;

        for (int i = 0 ; i <= n; i++)
        {

            int cnt = count(i);

            result.push_back(cnt);

        }

        return result;
        
    }
};
