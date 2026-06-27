class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.rbegin(), capacity.rend());

        int boxesUsed = 0;

        for (int cap : capacity) {
            totalApples -= cap;
            boxesUsed++;

            if (totalApples <= 0) {
                break;
            }
        }

        return boxesUsed;
    }
};