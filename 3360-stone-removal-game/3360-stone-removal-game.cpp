class Solution {
public:
    bool canAliceWin(int n) {
     bool t=false;
        int val=10;
        while(n>=val){
          t=1-t;
          n-=val;
          val--;
        }
        return t==true;
    }
};