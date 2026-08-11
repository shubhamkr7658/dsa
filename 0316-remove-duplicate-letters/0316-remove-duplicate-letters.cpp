class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        // Count remaining occurrences
        for(char c : s) {
            freq[c - 'a']++;
        }

        for(char c : s) {
            freq[c - 'a']--;

            // Already present in stack
            if(used[c - 'a'])
                continue;

            // Remove larger characters only if they occur again later
            while(!st.empty() &&
                  st.top() > c &&
                  freq[st.top() - 'a'] > 0) {
                
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c - 'a'] = true;
        }

        string ans = "";

        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};