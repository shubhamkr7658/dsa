class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int s=nums[0];
        int prev=nums[0];
        int ans1=nums[0];
        for(int i=1;i<n;i++){
            s+=nums[i];
            prev=max(nums[i],prev+nums[i]);
            ans1=max(ans1,prev);
        }
         prev=nums[0];
        int ans2=nums[0];
        for(int i=1;i<n;i++){
        prev=min(nums[i],nums[i]+prev);
          ans2=min(ans2,prev);
        }
        if(s-ans2==0){
            return ans1;
        }
        return max(s-ans2,ans1);
    }
};