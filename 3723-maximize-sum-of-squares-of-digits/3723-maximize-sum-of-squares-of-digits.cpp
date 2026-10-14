class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        string res = "";
        int rem = sum;
        if (rem < 10) {
            res +=to_string(rem);
            n--;
            while (n != 0) {
                res += '0';
                n--;
            }
            return res;
        }
        while (n != 0) {
            if (rem > 9) {
                res += '9';
                rem -= 9;
            } else {
                res += to_string(rem);
                rem=0;
            }
            n--;
        }
        if (n == 0 && rem > 0)
            return "";
        while (n != 0) {
            res += '0';
            n--;
        }
        return res;
    }
};