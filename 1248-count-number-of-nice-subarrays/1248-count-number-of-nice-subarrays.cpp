class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int c1=0;
        int c2=0;
     int t=k;
        int i=0;
        int j=0;
        while(j<n){
             
             if(nums[j]%2==1){
                k--;
             }
             while(k<0){
                if(  nums[i]%2==1){
                    k++;
                }
                i++;
             }
             c1+=(j-i)+1;
             j++;
        }
i=0;
 j=0;
k=t-1;
                while(j<n){
             
             if(nums[j]%2==1){
                k--;
             }
             while(k<0){
                
                if(nums[i]%2==1){
                    k++;
                }
                i++;
             }
             c2+=(j-i)+1;
             j++;
        }
        return c1-c2;
    }
};