class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int>d1;
        deque<int>d2;
        int n=nums.size();
        long long ans=0;
        int l=0;
        for(int i=0;i<n;i++){
          while(!(d1.empty())&& nums[i]>nums[d1.back()]){
            d1.pop_back();
          }
          d1.push_back(i);
          while(!(d2.empty())&& nums[i]<nums[d2.back()]){
            d2.pop_back();
          }
          d2.push_back(i);
          while(nums[d1.front()]-nums[d2.front()]>2){
             l++;
             if(d1.front()<l){
                d1.pop_front();
             }
             if(d2.front()<l){
                d2.pop_front();
             }
          }
          ans+=i-l+1;
        }
   return ans;
    }
};