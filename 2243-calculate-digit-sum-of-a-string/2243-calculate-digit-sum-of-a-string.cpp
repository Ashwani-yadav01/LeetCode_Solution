class Solution {
public:
    string sumOfDigits(string s) {
        int sum = 0;

        for (char ch : s) {
            sum += ch - '0';
        }

        return to_string(sum);
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            string res;
            int n = s.size();
            int i = 0;

            while (i < n) {
                string str = s.substr(i, k);
                res += sumOfDigits(str);
                i += k;
            }

            s = res;
        }

        return s;
    }
};