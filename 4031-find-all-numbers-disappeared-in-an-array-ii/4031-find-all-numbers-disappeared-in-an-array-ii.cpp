class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
         mp[nums[i]]++;
        }
        for(int j=lower;j<=upper;j++){
            int mi=upper+1;
            int ma=lower-1;
            if(mp.find(j)!=mp.end()){
                continue;
            }
            while(j<=upper&& mp.find(j)==mp.end()){
             mi=min(mi,j);
             ma=max(ma,j);
             j++;
            }
            ans.push_back({mi,ma});

        }
        return ans;
    }
};