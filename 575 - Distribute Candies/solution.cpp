class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st(candyType.begin(), candyType.end());
        int n = candyType.size();
        int setsize = st.size();
        return min(setsize, n / 2);
    }
};