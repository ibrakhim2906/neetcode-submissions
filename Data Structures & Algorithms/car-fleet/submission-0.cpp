class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos_speed{};

        for (int i = 0; i < position.size(); i++)
        {
            pos_speed.push_back({position[i], speed[i]});
        }

        sort(pos_speed.rbegin(), pos_speed.rend());

        vector<double> stck;

        for (auto& p : pos_speed)
        {
            stck.push_back((double)(target-p.first)/p.second);

            if (stck.size() >= 2 &&
                stck.back() <= stck[stck.size()-2])
                {
                    stck.pop_back();
                }
        }

        return stck.size();
    }
};
