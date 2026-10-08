class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int n=fruits.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(j<n){
           mp[fruits[j]]++;
           if(mp[fruits[j]]==1){
            k--;
           }
           while(k<0){
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0){
                k++;
            }
            i++;
           }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};