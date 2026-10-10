class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int m=0;
        int i=0;
        int j=0;
        while(j<n){
             if(nums[j]==0){
                k--;
             }
            if(k<0){
            if(nums[i]==0){
                k++;
            }
            i++;
            }
        m=max(j-i+1,m);
        j++;
        }
        return m;
    }
};