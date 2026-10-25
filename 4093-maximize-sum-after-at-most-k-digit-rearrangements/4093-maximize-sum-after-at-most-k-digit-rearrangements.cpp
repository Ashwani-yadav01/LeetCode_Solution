class Solution {
public:
    int ran(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end(), greater<char>());
        return stoi(s);
    }

    long long maximizeSum(vector<int>& arr, int k) {
        long long total_sum = 0;
        vector<int> gains;

        for (int val : arr) {
            total_sum += val; 
            int max_val = ran(val);
            gains.push_back(max_val - val);
        }

        sort(gains.begin(), gains.end(), greater<int>());

        for (int i = 0; i < gains.size() && i < k; ++i) {
            if (gains[i] > 0) {
                total_sum += gains[i];
            } else {
                break; 
            }
        }

        return total_sum;
    }
};