class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int f = 1;
        for(auto&el:nums)if(el!=0){f = 0;break;}
        if(f)return 0;
        int t = 0;
        for(auto&el:nums){
            t^=el;
        }
        if(t==0)return nums.size()-1;
        return nums.size();
    }
};