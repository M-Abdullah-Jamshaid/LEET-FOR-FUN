class Solution {
public:
    static bool cmp(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        
        if (countA == countB)
            return a < b;      // if same number of 1 bits, sort by value
        
        return countA < countB; // otherwise sort by number of 1 bits
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};