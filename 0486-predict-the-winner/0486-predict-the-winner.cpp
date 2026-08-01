class Solution {

public:

int dp[21][21][3];

int sol(vector<int>& nums,int l,int r,int f){

    if(l>r)return 0;

    if(dp[l][r][f]!=-1)return dp[l][r][f];

    if(f){

        return min(sol(nums,l+1,r,0),sol(nums,l,r-1,0));

    }

    int rht = 0,lft=0;

    

    lft = nums[l]+sol(nums,l+1,r,1);

    rht=nums[r]+sol(nums,l,r-1,1);



    return dp[l][r][f] = max(lft,rht);

    

}

bool predictTheWinner(vector<int>& nums) {

    int sum = 0;

    for(auto&el:nums){

        sum+=el;

    }

    memset(dp,-1,sizeof(dp));

    int ans = sol(nums,0,nums.size()-1,0);

    return sum-ans<=ans;

}

};