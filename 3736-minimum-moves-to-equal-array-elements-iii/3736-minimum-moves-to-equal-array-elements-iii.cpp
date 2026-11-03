class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int cost=0;
        for(int i=0;i<n;i++){
        cost+=abs(nums[i]-max);
        }
        return cost;
    }
};