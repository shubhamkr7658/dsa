class Solution {
public:
    int countMagicalPairs(string s) {
     int n=s.length();
        int ans=0;
  
        for(int j=0;j<n-1;j++){
        unordered_map<char,int>mpl;
        unordered_map<char,int>mpr;

        unordered_map<int,int>unl;
        unordered_map<int,int>unr;
            for(int i=j;i>=0;i--){
             mpl[s[i]]++;
             int si=mpl.size();
             unl[si]++;
            }
            for(int k=j+1;k<n;k++){
                mpr[s[k]]++;
                int si=mpr.size();
                unr[si]++;
            }
            for(int p=1;p<=26;p++){
                ans+=(unl[p]*unr[p]);
            }
        }
        return ans;
    }
};