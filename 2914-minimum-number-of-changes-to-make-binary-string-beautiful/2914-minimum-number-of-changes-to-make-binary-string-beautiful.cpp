class Solution {
public:
    int minChanges(string s) {
        int cost=0;
        int n=s.size();
        for(int i=0;i<n;i=i+2){
            if(s[i]!=s[i+1]){
                cost++;
            }
        }
        return cost;
    }
};