class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=-1;
        int r=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
            l=i-1;
            break;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
            r=i+1;
            break;
            }
        } 
        if(l==-1){
            return 0;
        }

        int mini=nums[l];
        int maxi=nums[r];  
        for(int i=l;i<=r;i++){
        mini=min(nums[i],mini);
        maxi=max(nums[i],maxi);
        }  
        for(int i=0;i<=l;i++){
            if(nums[i]>mini){
                l=i;
                break;
            }
        }
        for(int j=n-1;j>=r;j--){
            if(nums[j]<maxi){
                r=j;
                break;
            }
        }    
        return(r-l+1);
    }
};