class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int l = 0;
        int count = 0;

        multiset<int> st;

        for(int r = 0; r < nums.size(); r++) {

            st.insert(nums[r]);

            while(*st.rbegin() - *st.begin() > limit) {

                st.erase(st.find(nums[l]));
                l++;
            }

            count = max(count, r - l + 1);
        }

        return count;
    }
};