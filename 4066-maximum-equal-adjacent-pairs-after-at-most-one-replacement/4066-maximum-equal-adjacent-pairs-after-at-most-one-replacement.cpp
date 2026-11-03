class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>mp;
        int n=nums.size();
        int ans=0;
        int ma=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){  
            int a=min(nums[i],nums[i+1]);
            int b=max(nums[i],nums[i+1]);
            mp[{a,b}]++;
            ma=max(ma,mp[{a,b}]);
            }
            if(nums[i]==nums[i+1]) ans++;
        }
        return ans+ma;

    }
};