class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

int s=servers.size();
// auto lamda=[&](pair<int,int>&a,pair<int,int>&b){
//     if(servers[a.first]<servers[b.first]){
//         return true;
//     }
//     else if(servers[a.first]==servers[b.first]){
//         return true;
//     }
//     return false;
// };
auto lamda = [&](const pair<int,long long>& a, const pair<int,long long>& b) {
    if (servers[a.first] != servers[b.first]) {
        return servers[a.first] > servers[b.first];
    }
    return a.first > b.first;
};
auto lamda2 = [&](const pair<int,long long>& a, const pair<int,long long>& b) {
    if (a.second != b.second)
        return a.second > b.second;

    if (servers[a.first] != servers[b.first])
        return servers[a.first] > servers[b.first];

    return a.first > b.first;
};
  priority_queue<pair<int,long long>,vector<pair<int,long long>>,decltype(lamda)>pq1(lamda);
  priority_queue<pair<int,long long>,vector<pair<int,long long>>,decltype(lamda2)>pq2(lamda2);
  for (int i = 0; i < s; i++) {
    pq1.push({i, 0});
}
  int n=tasks.size();
  vector<int>ans(n,-1);
  long long time=0;
  int j=0;
  while(j<n){

 while(!(pq2.empty()) && time>=pq2.top().second){
     pq1.push(pq2.top());
     pq2.pop();
 }
 while(j<n && time>=j && !pq1.empty()){
    auto t=pq1.top();
    pq2.push({t.first,time+tasks[j]});
    ans[j]=t.first;
    pq1.pop();
    j++;
 }
if(pq1.empty()){
    time=pq2.top().second;
    continue;
}
 time++;
  }
  return ans;
    }
};