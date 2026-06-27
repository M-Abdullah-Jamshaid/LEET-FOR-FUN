class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        // Iterate through the array until just before the last possible
        // character's start. The loop condition 'i < n - 1' is key: we want to
        // stop when we are potentially looking at the very last character(s).
        while (i < n - 1) {
            // If the current bit is 1, it must be a two-bit character,
            // so skip two positions.
            if (bits[i] == 1) {
                i += 2;
            } else {
                // If the current bit is 0, it is a one-bit character,
                // so skip one position.
                i += 1;
            }
        }

        // After the loop finishes:
        // If 'i' is exactly 'n - 1', it means the last item decoded was a
        // single '0'. If 'i' is 'n', it means the last two-bit character
        // consumed the final '0'.
        return i == n - 1;
    }
};