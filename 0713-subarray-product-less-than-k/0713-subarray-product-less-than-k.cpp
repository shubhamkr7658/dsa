class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s=nums.size();
        int l=0;
        int r=0;
        int mul=1;
        int sum=0;
        while(r<s){
          mul=mul*nums[r];
         if(mul>=k){
            while(l<=r &&mul>=k){
                mul=mul/nums[l];
                l++;           
            }
         }
            sum=sum+(r-l+1);

         r++;
        }
        return sum;
    }
};