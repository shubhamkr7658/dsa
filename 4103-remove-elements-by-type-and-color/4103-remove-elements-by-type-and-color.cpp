class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& group) {
        vector<pair<pair<int,int>,int>>vec;
        stack<pair<pair<int,int>,int>>st;
        int n=types.size();
        int m=group.size();
        for(int i=0;i<n;i++){
            if(!(st.empty())&& st.top().first.first==types[i]&& st.top().first.second==colors[i]){
                int count=st.top().second+1;
                st.pop();
                if(count<group[types[i]]){
                    st.push({{types[i],colors[i]},count});
                }
            }
            else{
            if (group[types[i]] > 1) {
        st.push({{types[i], colors[i]}, 1});
    }
            }
        }
        if(st.empty())return true;
        return false;
    }
};