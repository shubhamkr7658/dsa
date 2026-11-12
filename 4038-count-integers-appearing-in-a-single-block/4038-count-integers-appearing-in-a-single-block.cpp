class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int temp=1;
            while(i<n-1 && nums[i+1]==nums[i]){
                temp++;
                i++;
            }
            if(temp==mp[nums[i]]){
                count++;
            }
        }
        return count;
    }
};