class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        for(int val:nums){
            mn=min(mn,val);
        }
        int moves=0;
        for(int val:nums){
            moves+=abs(val-mn);
        }
        return moves;
    }
};