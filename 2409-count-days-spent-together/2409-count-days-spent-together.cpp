class Solution {
public:
    int countDaysTogether(string arriveA, string leaveA,
                          string arriveB, string leaveB) {

        vector<int> month = {31,28,31,30,31,30,
                             31,31,30,31,30,31};

        // Find the later arrival date
        string start = max(arriveA, arriveB);

        // Find the earlier leaving date
        string end = min(leaveA, leaveB);

        // No overlap
        if (start > end) {
            return 0;
        }

        int sm = stoi(start.substr(0, 2));
        int sd = stoi(start.substr(3, 2));

        int em = stoi(end.substr(0, 2));
        int ed = stoi(end.substr(3, 2));

        // Same month
        if (sm == em) {
            return ed - sd + 1;
        }

        // Different months
        int ans = month[sm - 1] - sd + 1;

        for (int i = sm; i < em - 1; i++) {
            ans += month[i];
        }

        ans += ed;

        return ans;
    }
};