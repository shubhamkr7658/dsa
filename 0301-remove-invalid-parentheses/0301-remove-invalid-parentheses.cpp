// class Solution {
// public:
// vector<string>ans;
// void dfs(string s,int i,int &n,int c){
//   if(i==n){
//    if(c==0){
//     ans.push_back(s);
//    }
//    return;
//   }
//   if(s[i]=='(') c++;
//   else{
//     c--;
//   }
//   if(c<0){
//     for(int k=i-1;k>=0;i--){
//         if(s[k])
//         dfs(s,k,n,c=c+1);
//     }
//   }


// }
//     vector<string> removeInvalidParentheses(string s) {
//         int n=s.length();
//    dfs(s,0,n);
        
//     }
// };


class Solution {
    void remove(string s, int scanStart, int deleteStart, char open, char close,
                vector<string>& answers) {
        int balance = 0;

        for (int i = scanStart; i < (int)s.size(); i++) {
            if (s[i] == open) {
                balance++;
            } else if (s[i] == close) {
                balance--;
            }

            if (balance >= 0) {
                continue;
            }

            for (int j = deleteStart; j <= i; j++) {
                if (s[j] == close && (j == deleteStart || s[j - 1] != close)) {
                    remove(s.substr(0, j) + s.substr(j + 1), i, j, open, close,
                           answers);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            remove(s, 0, 0, ')', '(', answers);
        } else {
            answers.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answers;
        remove(s, 0, 0, '(', ')', answers);
        return answers;
    }
};