class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
vector<int> blow;
vector<int> end;
        for(int i=0;i<n;i++){
            blow.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(blow.begin(),blow.end());
        sort(end.begin(),end.end());
        int p=people.size();
        vector<int>ans;
        for(int i=0;i<p;i++){  
        int a=upper_bound(blow.begin(),blow.end(),people[i])-blow.begin();
        int b=lower_bound(end.begin(),end.end(),people[i])-end.begin();
        ans.push_back(a-b);
        }
  return ans;
    }
};