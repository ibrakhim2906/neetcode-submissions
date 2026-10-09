class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int count[26] = {0};

        for (auto task : tasks)
        {
            count[task-'A']++;
        }

        priority_queue<int, std::vector<int>> maxHeap{};

        for (auto cnt : count)
        {
            if (cnt > 0) maxHeap.push(cnt);
        }

        deque<pair<int,int>> q{};

        int time = 0;

        while (!maxHeap.empty() || !q.empty())
        {
            time++;

            if (!maxHeap.empty()) {
                int cd = maxHeap.top()-1;
                maxHeap.pop();
                
                if (cd > 0)
                {
                    q.push_back({cd, time + n});
                }
            }

            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop_front();
            }
        }

        return time;
    }
};