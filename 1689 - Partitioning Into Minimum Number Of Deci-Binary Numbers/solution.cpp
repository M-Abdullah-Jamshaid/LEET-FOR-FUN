class Solution {
public:
    int minPartitions(string n) {
        char max_digit = '0';
        
        for (char c : n) {
            if (c > max_digit) {
                max_digit = c;
            }
            
            if (max_digit == '9') break;
        }
        
        return max_digit - '0';
        
    }
};