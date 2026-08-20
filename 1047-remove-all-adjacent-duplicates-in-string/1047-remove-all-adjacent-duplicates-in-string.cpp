class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";

        for (char c : s) {
            if (!temp.empty() && temp.back() == c) {
                temp.pop_back();
            } 
            else {
                temp.push_back(c);
            }
        }

        return temp;
    }
};