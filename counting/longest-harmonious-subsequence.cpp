class Solution {
public:
    int solution1(vector<int>& nums) {
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
    int solution2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i+= mp[nums[i]]) {
            int num = nums[i];
            int len = mp[num];
            if (i + len < nums.size() && nums[i + mp[num]] == num + 1) {
                ans = max(ans, mp[num] + mp[num + 1]);
            }
        }
        return ans;

    }
    int findLHS(vector<int>& nums) {
        //return solution1(nums);
        return solution2(nums);
        
        
    }
};