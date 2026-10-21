class Solution {
public:
    int minOperations(string s) {
        string res = s;
        int n = s.size();
        sort(res.begin(), res.end());
        if (res == s)
            return 0;
        if (s.size() <= 2 && s != res)
            return -1;
        string t=s;
        sort(t.begin() + 1, t.end());
        if (t == res)
            return 1;
        t=s;
        sort(t.begin() , t.end()-1);
        if (t == res)
            return 1;

        t=s;
        sort(t.begin(),t.end()-1);
        sort(t.begin()+1,t.end());
        if(t==res) return 2;
        t=s;
        sort(t.begin()+1,t.end());
        sort(t.begin(),t.end()-1);

        if(t==res) return 2;


        return 3;
    }
};