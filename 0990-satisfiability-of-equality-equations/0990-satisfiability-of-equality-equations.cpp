class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int i){
    if(parent[i]==i){
        return i;
    }
    return parent[i]=find(parent[i]);
}
void uni(int i,int j){
    int a=find(i);
    int b=find(j);
 if(a==b){
    return;
 }
 if(rank[a]>rank[b]){
    parent[b]=a;
 }
 else if(rank[b]>rank[a]){
    parent[a]=b;
 }
 else{
    parent[a]=b;
    rank[a]++;
 }
}
    bool equationsPossible(vector<string>& equations) {
    for(int i=0;i<26;i++){
        parent.push_back(i);
    }
    rank.assign(26,0);
      for(auto &t:equations){
        if(t[1]=='='){
            uni((t[0]-'a'),t[3]-'a');
        }
      }  
      for(auto &t:equations){
        if(t[1]=='!'){
            int a=find(t[0]-'a');
            int b=find(t[3]-'a');
            if(a==b){
                return false;
            }
        }
      }
    
      return true;
    }
};