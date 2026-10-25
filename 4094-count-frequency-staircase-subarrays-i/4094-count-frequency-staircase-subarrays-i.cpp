class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            vector<int> order;
            int current_length = 0;

            for (int j = i; j < n; j++) {
                int val = nums[j];
                
                if (freq[val] == 0) {
                    order.push_back(val);
                }
                freq[val]++;
                current_length++;

                int k = order.size();
                int required_length = k * (k + 1) / 2;

               
                if (current_length == required_length) {
                    bool isValid = true;
                    for (int m = 0; m < k; m++) {
                        if (freq[order[m]] != m + 1) {
                            isValid = false;
                            break;
                        }
                    }
                    if (isValid) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};// this is not my approach it coded by gemini ai