class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> vec(26, 0);

        for (char c : s) {
            vec[c - 'a']++;
        }

        string ans = "";
        int i = 0;

        // Step 1: target ko jitna match kar sakte hain karo
        for (; i < t.length(); i++) {
            if (vec[t[i] - 'a'] > 0) {
                ans += t[i];
                vec[t[i] - 'a']--;
            } 
            else {
                break;
            }
        }

        // Step 2: current position se backtrack
        for (int pos = i; pos >= 0; pos--) {

            // Agar pura target match ho gaya tha
            if (pos == t.length()) {
                vec[ans.back() - 'a']++;
                ans.pop_back();
                pos--;
            }
            
            // Previous position par jaane par character wapas karo
            else if (pos < ans.length()) {
                vec[ans.back() - 'a']++;
                ans.pop_back();
            }

            if (pos < 0) break;

            // t[pos] se greater smallest character
            int j = t[pos] - 'a' + 1;

            while (j < 26 && vec[j] == 0) {
                j++;
            }

            if (j < 26) {
                ans += char('a' + j);
                vec[j]--;

                // Remaining characters sorted order mein
                for (int k = 0; k < 26; k++) {
                    while (vec[k] > 0) {
                        ans += char('a' + k);
                        vec[k]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};