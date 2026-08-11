class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int j;
        int count=0;

        for(j=1;j<nums.size();j++){
            if(nums[j]==nums[j-1]+1){
             sum+=nums[j];
             count++;
             continue;
            }
         break;
        }
        sort(nums.begin()+j,nums.end());

    if(count==0){
        sum=nums[0]+1;
    }
     for(;j<nums.size();j++){
            if (nums[j] < sum)
            continue;
        if(nums[j]==sum)
         sum++;
        else{
         break;
        }
     }
     return sum;
    }
};