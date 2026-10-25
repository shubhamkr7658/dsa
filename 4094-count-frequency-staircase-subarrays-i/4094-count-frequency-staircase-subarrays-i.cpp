class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        unordered_map<int,int>order;
        unordered_map<int,int>freq;
        int curr=1;
        int good=0;
        for(int j=i;j<n;j++){
         int o=order[nums[j]];
         if(!o){
            order[nums[j]]=curr;
            curr++;
         }
         freq[nums[j]]++;
        if(freq[nums[j]]>order[nums[j]]){
            break;
         }
         if(freq[nums[j]]==order[nums[j]]){
            good++;
         }
         if(good==curr-1){
            ans++;
         }

        }
    }
    return ans;
    }
};