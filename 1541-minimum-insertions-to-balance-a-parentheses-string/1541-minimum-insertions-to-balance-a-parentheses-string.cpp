
class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int need = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                    } else {
                        need++;
                    }
                    i++;
                } else {
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                        need++;
                    } else {
                        need += 2;
                    }
                }
            }
        }

        need += 2 * st.size();
        return need;
    }
};
