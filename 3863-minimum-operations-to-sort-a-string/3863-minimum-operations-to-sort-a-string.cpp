class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        if(s.size()==2){
            return -1;

        }
char mi = *min_element(s.begin(), s.end());
char ma = *max_element(s.begin(), s.end());
      if(s[0]==mi || s[n-1]==ma){
        return 1;
      }
      else if(s[0]==ma&&s[n-1]==mi &&count(s.begin(),s.end(),mi)==1 && count(s.begin(),s.end(),ma)==1){
        return 3;
      }
      return 2;
      

    }
};