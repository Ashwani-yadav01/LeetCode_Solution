class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {

        priority_queue<pair<int,int>, vector<pair<int,int>>,
                       greater<pair<int,int>>> available;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busy;

        int n = s.size();
        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < n; i++) {
            available.push({s[i], i});
        }

        for (int i = 0; i < t.size(); i++) {

            time = max(time, (long long)i);

            while (!busy.empty() && busy.top().first <= time) {
                int index = busy.top().second;
                busy.pop();

                available.push({s[index], index});
            }

            if (available.empty()) {
                time = busy.top().first;

                while (!busy.empty() && busy.top().first <= time) {
                    int index = busy.top().second;
                    busy.pop();

                    available.push({s[index], index});
                }
            }

            int index = available.top().second;
            available.pop();

            ans.push_back(index);

            busy.push({time + t[i], index});
        }

        return ans;
    }
};