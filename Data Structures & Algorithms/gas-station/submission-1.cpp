class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int size = gas.size();

        int existsTotal = 0;

        for (int i = 0 ; i < size ; i ++)
        {

            existsTotal+=(gas[i]-cost[i]);
            
        }

        if (existsTotal < 0)
        {
            return -1;
        }

        int total = 0;
        int result = 0;

        for (int i = 0 ; i < size; i++)
        {
            total += gas[i]-cost[i];

            if (total < 0)
            {
                total = 0;
                result = i+1;
            }

        }

        return result;
        
    }
};
