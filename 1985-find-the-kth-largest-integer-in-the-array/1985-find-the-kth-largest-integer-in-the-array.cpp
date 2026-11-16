class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
                auto cmp = [](string& a, string& b) {
            if (a.length() == b.length())
                return a > b;

            return a.length() > b.length();
        };
        priority_queue<string,vector<string>,decltype(cmp)>que;
        for(int i=0;i<n;i++){
            que.push(nums[i]);
            while(que.size()>k){
                que.pop();
            }
        }
        return que.top();
    }
};