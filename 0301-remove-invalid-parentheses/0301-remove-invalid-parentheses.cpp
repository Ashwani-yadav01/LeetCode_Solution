class Solution {
public:
    int n;
    int valid;
    vector<string> result;

    bool isValid(string s) {
        int balance = 0;
        for (char ch : s) {
            if (ch == '(') {
                balance++;
            } 
            else if (ch == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void solve(string &s, int i, string &str, int count) {

        if (count > valid)
            return;

        if (i == n) {
            if (count == valid && isValid(str)) {
                result.push_back(str);
            }
            return;
        }

        if (s[i] == '(' || s[i] == ')') {

            str.push_back(s[i]);
            solve(s, i + 1, str, count);
            str.pop_back();

            solve(s, i + 1, str, count + 1);

        } 
        else {
            str.push_back(s[i]);
            solve(s, i + 1, str, count);
            str.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();

        int open = 0;
        int close = 0;

        for (char ch : s) {

            if (ch == '(') {
                open++;
            } 
            else if (ch == ')') {

                if (open > 0)
                    open--;
                else
                    close++;
            }
        }

        valid = open + close;

        string str;
        solve(s, 0, str, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};