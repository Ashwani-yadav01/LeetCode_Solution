class Solution {
public:
    int countAdjacent(string s) {
        int count = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            }
        }

        return count;
    }
    int countRotations(string s, int k) {
        vector<string> prefixes;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            string sub = s.substr(i, s.size());
             string prefix =
                s.substr(0, i );
            int res = countAdjacent(sub + prefix);
            if (res == k) {
                result++;
            }
        }
        return result;
    }
};