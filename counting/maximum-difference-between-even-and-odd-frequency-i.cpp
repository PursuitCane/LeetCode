class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        int max_odd = 0;
        int min_even = s.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] & 1) {
                max_odd = max(max_odd, freq[i]);
            } else {
                min_even = min(min_even, freq[i]);
            }
        }
        return max_odd - min_even;
                
    }
};