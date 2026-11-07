class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
auto lamda=[](vector<int>a1,vector<int>a2){
             if(a1[1]<a2[1]){
                return true;
             }
             else
             return false;
};
sort(logs.begin(),logs.end(),lamda);
vector<pair<int,int>>qu;
        int q = queries.size(); 
        for(int i = 0; i < q; i++) qu.push_back({queries[i], i}); 
        sort(qu.begin(), qu.end());
  vector<int>ans(q,0);
        int l=0;
        int r=0;
        unordered_map<int, int> smp;
        for(int i=0;i<qu.size();i++){
           int st=qu[i].first-x;
           int end=qu[i].first;
           while(r<logs.size()&& logs[r][1]<=end){
            smp[logs[r][0]]++;
            r++;
           }
           while(l<r && logs[l][1]<st){
            smp[logs[l][0]]--; 
            if(smp[logs[l][0]] == 0) smp.erase(logs[l][0]);
            l++;
           }
           ans[qu[i].second]=n-smp.size();
        }
         return ans;
        }

};