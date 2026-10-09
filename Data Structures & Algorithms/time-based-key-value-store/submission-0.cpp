class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        
        vector<pair<string, int>>& arr = mp[key];

        int l = 0, r = arr.size() -1;

        string result = "";

        while (l<=r)
        {
            int m = l + (r-l)/2;

            if (arr[m].second <= timestamp)
            {
                result = arr[m].first;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return result;
        
        
    }
};
