class Solution {
public:
    int findLHS(vector<int>& nums) {
        set<int> st;
        map<int, int> ht;
        for (auto num : nums) {
            ht[num]++;
            st.insert(num);
        }
        int ans = 0;
        for (auto n : st) {
            if (st.count(n+1)) {
                ans = max(ans, ht[n] + ht[n+1]);
            }
        }
        return ans;
        
    }
};