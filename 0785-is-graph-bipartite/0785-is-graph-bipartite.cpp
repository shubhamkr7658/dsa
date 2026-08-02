class Solution {
public:
vector<int>color;
unordered_map<int,vector<int>>adj;
queue<int>que;
bool bfs(unordered_map<int,vector<int>>&adj,int i,vector<int>&color,int col){
    color[i]=col;
    que.push(i);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(auto &t:adj[u]){
            if(color[t]==-1){
                color[t]=1-color[u];
                que.push(t);
            }
            else if(color[t]==color[u])
                return false;
            
        }
        
    }
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
for(int u = 0; u < graph.size(); u++) {
    for(int v : graph[u]) {
        adj[u].push_back(v);
    }
}

        int n = graph.size();
        color.assign(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){ 
            if(!bfs(adj,i,color,0)){
                return false;
            }
            }
        }
        return true;
    }
};