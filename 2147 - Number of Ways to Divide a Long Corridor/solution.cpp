class Solution {
public:
    int numberOfWays(string corridor) {
       vector<int> seats;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }

        if (seats.size() == 0 || seats.size() % 2 != 0) {
            return 0;
        }

        
        long long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 2; i < seats.size(); i += 2) {
            int prev_seat_index = seats[i - 1];
            int curr_seat_index = seats[i];
            int ways = curr_seat_index - prev_seat_index;
            
            ans = (ans * ways) % MOD;
        }

        return (int)ans;
    }
};