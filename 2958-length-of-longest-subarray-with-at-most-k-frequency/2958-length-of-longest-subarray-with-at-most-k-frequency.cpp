class Solution {
public:
unordered_map<int,int>map;
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;int r=0;
        int count=0;
     while(r<nums.size()){
       map[nums[r]]++;
       if(map[nums[r]]<=k){
        count=max(count,r-l+1);
       }
       else{
        while(map[nums[r]]>k){
            map[nums[l]]--;
            l++;
        }
       }
       r++;
       }
       return count;
    }
    
     
    
};