class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        vector<int>p(n,0);
        for(int i=0;i<n;i++){
            string temp=to_string(nums[i]);
            sort(temp.begin(),temp.end(),greater<char>());
          p[i]=stoi(temp)-nums[i];
        }
        sort(p.begin(),p.end(),greater<int>());
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<k;i++){
       sum+=p[i];
        }
        return sum;
    }
};