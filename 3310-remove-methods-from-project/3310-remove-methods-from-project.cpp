class Solution {
public:
queue<int>que;
vector<int>ans;
vector<int>visit;
vector<vector<int>>adj;
void bfs(vector<vector<int>>&adj,int &k){
que.push(k);
visit[k]=1;
    while(!(que.empty())){
        int i=que.front();
        que.pop();
        for(auto &t:adj[i]){
            if(visit[t]==0){ 
                visit[t]=1;
                que.push(t);
            }
        }
    }
}
void final(int n){
    for(int i=0;i<n;i++){
        ans.push_back(i);
    }
   
}

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        bool f=false;
            visit.assign(n,0);
        adj.assign(n,{});
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        int i;
     bfs(adj,k);
           
    for(auto &t:invocations){
        if(visit[t[0]]==0 &&visit[t[1]]==1 && f==false){
            f=true;
            break;
        }
    }
      
           
    if(f){
        final(n);
        }
    else{
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                ans.push_back(i);
            }
        }
    }
        
         return ans;
    
        }

    
};