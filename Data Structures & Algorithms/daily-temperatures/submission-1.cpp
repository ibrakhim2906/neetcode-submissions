class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stck;

        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];

            while (!stck.empty() && t > stck.top().first)
            {
                auto pr = stck.top();
                stck.pop();
                res[pr.second] = i - pr.second;
            }

            stck.push({t,i});
        }

        return res;
    }
};
