class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long mini=LLONG_MAX;
        int i=0;
        int j=0;
        while(i<n-1){
            j=i;
            while(j<n && nums[j]==nums[i]){
                j++;
            }
            if(j-1>=1)
            mini=min(mini,(1LL *i * nums[i]+1LL *(n-(j-1)-1)*nums[i]));
            i=j;
        }
        return mini;
    }
};