class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, pair<int, vector<int>>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].first++;
            mp[nums[i]].second.push_back(i);
        }
        int count = 0;
        for (auto val : mp) {
            if (val.second.first == 3) {
                vector<int> pos = val.second.second;

                if (pos[1] - pos[0] == pos[2] - pos[1]) {
                    count++;
                }
            }
        }
        return count;
    }
};