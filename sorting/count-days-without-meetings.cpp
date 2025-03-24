class Solution {
public:
    
    int countDays(int days, vector<vector<int>>& meetings) {
        auto lambda = [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        };
        sort(meetings.begin(), meetings.end(), lambda);
        
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < meetings.size(); i++) {
            int st = meetings[i][0];
            int end = meetings[i][1];
            if (st > curr) {
                ans += (st - curr - 1);
                curr = end;
                
            } else {
                curr = end;
            }
            if (curr >= days) break;
        }
        if (curr < days) {
            ans += days - curr;
        }
        return ans;

    }
};