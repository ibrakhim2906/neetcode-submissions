class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n, 0);

        vector<int>& prevRow = prev;

        for(int i = m-1; i >=0 ;i--)
        {
            vector<int> currRow(n, 0);

            currRow[n-1] = 1;

            for (int j = n-2; j>=0; j--)
            {
                currRow[j] = prevRow[j] + currRow[j+1];
            }

            prevRow = currRow;
        }

        return prevRow[0];


        
    }
};
