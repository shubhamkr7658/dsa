class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sum3=INT_MIN;
        stack<int>st;
        int size=nums.size();
        int sum2=INT_MIN;
        for(int i=size-1;i>=0;i--){
     while(!(st.empty()) && st.top()<nums[i]){
        sum3=st.top();
        st.pop();
     }
     st.push(nums[i]);
       if(nums[i]<sum3){
                return true;
            }
        }
        return false;
    }
};