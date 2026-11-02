class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& lock, int k) {
        int p=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1 && lock[i]==1){
                lock[i]=0;
                p++;
            }
        }
        if(p>k){
            return -1;
        }
        int swapn=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i-1;j++){
                if(nums[j]>nums[j+1]){
                 if(lock[j]==1){
                    p++;
                            if(p>k){
            return -1;
        }
                    lock[j]=0;
                 }
                 if(lock[j+1]==1){
                    p++;
                            if(p>k){
            return -1;
        }
                    lock[j+1]=0;
                 }
                 swap(nums[j],nums[j+1]);
                 swapn++;
                }
            }
        }
        return p+swapn;
    }
};