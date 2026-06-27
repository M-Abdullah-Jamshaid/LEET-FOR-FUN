class Solution {
public:
    string getHappyString(int n, int k) {
        if (n < 62) {
        long long maxK = 3LL * (1LL << (n - 1)); 
        if (k > maxK || k <= 0) return ""; 
    }

    // Convert to 0-indexed for the math
    k--; 

    string result = "";
    string alphabet = "abc";

    // 2. Determine the first character
    // We use (1LL << (n-1)) which is a fast way to write 2^(n-1)
    long long blockSize = (n > 62) ? 0 : (1LL << (n - 1));
    
    int firstIdx;
    if (n > 62) {
        // If n is huge, the first 10^18 strings all start with 'a'
        firstIdx = 0; 
    } else {
        firstIdx = k / blockSize;
        k %= blockSize;
    }
    result += alphabet[firstIdx];

    // 3. Determine remaining n-1 characters
    for (int i = 1; i < n; i++) {
        // Update block size for the next position (halving)
        if (n - 1 - i < 62) {
            blockSize = (1LL << (n - 1 - i));
        } else {
            blockSize = 0; // Still too large to fit in long long
        }

        // Filter available characters (cannot be the same as the previous)
        string available = "";
        for (char c : alphabet) {
            if (c != result.back()) {
                available += c;
            }
        }

        // Logic: pick between the 2 available characters
        int nextIdx;
        if (blockSize == 0) {
            nextIdx = 0; // Range is so large k hasn't reached the second option
        } else {
            nextIdx = k / blockSize;
            k %= blockSize;
        }
        
        result += available[nextIdx];
    }

    return result;
    }
};