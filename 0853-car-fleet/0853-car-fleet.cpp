class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>val;
        stack<float>st;
        for(int i=0;i<speed.size();i++){
            val.push_back({position[i],speed[i]});
        }
        sort(val.begin(),val.end());
        for(auto &t:val){
            int p=t.first;
            float s=t.second;
            float avg=(target-p)/s;
        while(!(st.empty())&& st.top()<=avg){
            st.pop();
        }
        st.push(avg);
        }
        return st.size();
    }
};