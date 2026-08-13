class Solution {
public:
    bool canChange(string start, string target) {
      int s=start.length();
      int i=0;
      int j=0;
      while(i<s && j<s ){
        while(i<s && start[i]=='_')i++;
        while(j<s && target[j]=='_')j++;
        if(i >= s || j >= s)
        break;
        if(start[i]!=target[j]){ return false;}
        else{
            if(start[i]=='L' && i<j){return false;}
            else if(start[i]=='R'&& i>j){ return false;}
            else{
                i++;
                j++;
            }
        }
      }  
   while(i<s && start[i]=='_'){ i++;}
   while(j<s && target[j]=='_'){j++;}
   if(i>=s && j<s){return false;} if(j>=s && i<s){return false;} return true;
    }
};