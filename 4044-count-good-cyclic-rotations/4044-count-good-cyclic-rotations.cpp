class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long sum2=0;
        long long sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i<n/2){
                sum2+=nums[i];
            }
        }
      int i=0;
      int j=n/2;
  while(i<n){
    if(sum-sum2<sum2){
        count++;
    }
    sum2-=nums[i];
    sum2+=nums[j%n];
    i++;
    j++;

  }
        return count;
    }
};