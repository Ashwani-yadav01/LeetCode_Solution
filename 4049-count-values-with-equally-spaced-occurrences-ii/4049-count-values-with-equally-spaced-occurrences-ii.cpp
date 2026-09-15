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
            vector<int> pos = val.second.second;

            if (pos.size() <= 2) {
                continue;
            }

            bool equallySpaced = true;
            int diff = pos[1] - pos[0];

            for (int i = 2; i < pos.size(); i++) {
                if (pos[i] - pos[i - 1] != diff) {
                    equallySpaced = false;
                    break;
                }
            }

            if (equallySpaced) {
                count++;
            }
        }
        return count;
    }
};