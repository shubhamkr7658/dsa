class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      int n=nums.size();
      int count=0;
      for(int i=1;i<n;i++){
         if(count==0 &&nums[i]<nums[i-1]){
            if(i>1 && nums[i]<nums[i-2]){
                nums[i]=nums[i-1];
             count=1;
            }
            else {
                nums[i-1]=nums[i];
                count=1;
            }
         }
         else if(nums[i]<nums[i-1]&& count==1){
            return false;
         }
         
      } 
      return true; 
    }
};