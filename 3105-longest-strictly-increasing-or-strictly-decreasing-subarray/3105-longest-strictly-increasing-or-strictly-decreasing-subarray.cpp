class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int count=0;
       while(i<n-1&&nums[i]<nums[i+1]){
        count++;
        ans=max(count,ans);
        i++;
       }
        }
    for(int i=0;i<n-1;i++){
            int count=0;
       while(i<n-1&& nums[i]>nums[i+1]){
        count++;
        ans=max(count,ans);
        i++;
       }
        }
        return ans+1;
    }
};