class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<pair<int, int>> st;

        for (int i = 0; i < m; i++) {
            bool flag = false;
            pair<int, int> first;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && flag == false) {
                    flag = true;
                    first = {i, j};
                }
                else if (grid[i][j] == 1) {
                    st.insert(first);
                    st.insert({i, j});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            bool flag = false;
            pair<int, int> first;

            for (int j = 0; j < m; j++) {
                if (grid[j][i] == 1 && flag == false) {
                    flag = true;
                    first = {j, i};
                }
                else if (grid[j][i] == 1) {
                    st.insert(first);
                    st.insert({j, i});
                }
            }
        }

        return st.size();
    }
};