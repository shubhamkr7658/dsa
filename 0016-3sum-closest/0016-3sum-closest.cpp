class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int close=500000;
        for(int i=0;i<=n-3;i++){
            int j=i+1;
            int k=n-1;
            int sum=0;
            while(j<k){
              sum=nums[i]+nums[j]+nums[k];
              if(abs(target-sum)<abs(target-close)){
                close=sum;      
              }
              if(target>sum){
                j++;
              }
              else{
                k--;
              }
            }
        }
        return close;
    }
};