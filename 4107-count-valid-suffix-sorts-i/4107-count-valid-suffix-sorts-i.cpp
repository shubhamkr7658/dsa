class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        int count=1;
        int i;
        for(i=0;i<n;i++){
            if(target[i]!=nums[i]){
                break;
            }
        }
        sort(nums.begin()+i,nums.end(),[](int a,int b){
            return a>b;
        });
        for(int p=0;p<n;p++){
            if(nums[p]!=target[p]){
                return 0;
            }
        }
        for(int p=min(i-1,n-2);p>=0;p--){
            if(nums[p]>=nums[p+1]){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};