class Solution {
public:
    long long countValidSubstrings(string s) {
        int n=s.length();
        int a=-1;
        int b=-1;
        int last=-1;
        long long count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            a=i;
        }
        if(s[i]=='b'){
            b=a;
        }
        if(s[i]=='c'){
       last=b;
        }
        count+=i-last;
    }
   return count;
    }
};