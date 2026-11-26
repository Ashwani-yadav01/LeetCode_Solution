class Solution {
public:
    bool canAliceWin(int n) {
        bool flag=true;
        int move=10;
        while(n>0){
            if(n<move){
                if(flag){
                    return false;
                }else {
                    return true;
                }
            }
            n-=move;
            move--;
            flag=!flag;
        }
      return flag==true?false:true;
    }
};