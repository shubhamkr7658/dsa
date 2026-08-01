class Solution {
public:
int solve(vector<int>&nums,int i,int j,int f){
    if(i>j){
        return 0;
    }
    int left,right=0;
    if(f){
     return min(solve(nums,i+1,j,0),solve(nums,i,j-1,0));
    }
    return max((nums[i]+solve(nums,i+1,j,1)),nums[j]+solve(nums,i,j-1,1));
}
    bool predictTheWinner(vector<int>& nums) {
        int ans=solve(nums,0,nums.size()-1,0);
        int sum=0;
        for(auto &t:nums){
       sum+=t;
        }
        return (sum-ans<=ans);
    }
};