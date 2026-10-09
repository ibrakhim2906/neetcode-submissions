class Twitter {
   public:
    unordered_map<int, unordered_set<int>> users;

    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;
    Twitter() : users{}, tweets{}, time{0} {}

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followed = users[userId];

        followed.insert(userId);

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (auto f : followed) {
            for (int i = tweets[f].size() - 1; i >= 0; i--) {
                minHeap.push(tweets[f][i]);

                if (minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }

        vector<int> res;


        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();

        }

        reverse(res.begin(), res.end());

        return res;
    }

    void follow(int followerId, int followeeId) { users[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { users[followerId].erase(followeeId); }
};
