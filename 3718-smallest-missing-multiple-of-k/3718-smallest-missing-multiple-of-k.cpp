class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>temp;
        int t=100/k+1;
        temp.assign(100/k+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                temp[nums[i]/k]=1;
            }
        }
        int j=1;
        for(j=1;j<t;j++){
         if(temp[j]==0){
            return j*k;
         }
        }
        return j*k;
    }
};