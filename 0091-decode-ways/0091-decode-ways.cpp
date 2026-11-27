class Solution {
public:
int solve(string &s,int n,int i,vector<int>&vec){
    if(i==n){
        return 1;
    }
    if(s[i]=='0'){
        return 0;
    }
    if(vec[i]!=-1){
        return vec[i];
    }
    int ans=0;
    if(s[i]>0){
    ans=solve(s,n,i+1,vec);
    }
    if(i<n-1){   
    string t=s.substr(i,2);
    if(t[0]=='0'){
        return 0;
    }
    int num=stoi(t);
    if(num>0 &&num<=26 ){
        ans+=solve(s,n,i+2,vec);
    }
    }
    return vec[i]=ans;
}
    int numDecodings(string s) {
        int n=s.length();
        vector<int>vec(n+1,-1);
        return solve(s,n,0,vec);
    }
};