class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int i;
      int n=arrival.size();
      set<int>st;
              priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq2;
      vector<int>cou(k,0);
      for(int s=0;s<k;s++){
      st.insert(s);
      }
      for(i=0;i<n;i++){
     while(!(pq2.empty())&& pq2.top().first<=arrival[i]){
        st.insert(pq2.top().second);
        pq2.pop();
     }
    
       if(!st.empty()){
        int t=arrival[i]+load[i];
        auto val = st.lower_bound(i % k);
        if(val==st.end()){
            val=st.begin();
        }
        cou[*val]++;
        pq2.push({arrival[i]+load[i],*val});
        st.erase(val);
       }
      }
      int maxi=0;
    for(int i=0;i<k;i++){
    maxi=max(maxi,cou[i]);
    }
    vector<int>ans;
    for(int i=0;i<k;i++){
        if(cou[i]==maxi){
            ans.push_back(i);
        }
    }
     return ans;
    }
};