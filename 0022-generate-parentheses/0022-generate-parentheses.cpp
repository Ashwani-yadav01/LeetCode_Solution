class Solution {
public:
    void generate(vector<string>& ans, int open, int close, string  s) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
        }
        if (open > 0) {
            generate(ans, open - 1, close, s + "(");
        }
        if (close > open) {
            generate(ans, open, close - 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string s = "";
        vector<string> ans;
        generate(ans, open, close, s);
        return ans;
    }
};