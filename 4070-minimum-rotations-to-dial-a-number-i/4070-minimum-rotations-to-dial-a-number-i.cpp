class Solution {
public:
    int minRotations(string s) {
        int res = 0;
        int l = 0;

        for (char ch : s) {
            int n = ch - '0';

            int rotation = min(abs(n - l), 10 - abs(n - l));


            l = n;
            res += rotation;
        }

        return res;
    }
};