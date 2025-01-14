class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        vector<int> C(A.size());
        for (int i = 0; i < A.size(); i++) {
            s.insert(A[i]);
            for (int j = 0; j <= i; j++) {
                if (s.count(B[j])) C[i]++;
            }
        }
        return C;
        
    }
};