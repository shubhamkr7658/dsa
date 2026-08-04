class Solution {
public:
vector<int>map;
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        map.assign(maxi-mini+1,-1);
        for(int i=0;i<nums.size();i++){
            map[nums[i]-mini]=1;
        }
        for(int i=0;i<map.size();i++){
        if(map[i]==-1)
          ans.push_back(i+mini);
        }
        return ans;
    
    }
};