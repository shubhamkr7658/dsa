class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            while(vec.size()>0 && vec.back()>nums[i] && vec.size() - 1 + (n - i) >= k){
                vec.pop_back();
            }
            vec.push_back(nums[i]);

        }
        while(vec.size()>k){
            vec.pop_back();
        }
        return vec;
    }
};