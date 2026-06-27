class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> ticket_counter;

        for(int i = 0; i < tickets.size(); i++) {
            
            ticket_counter.push({i, tickets[i]});
        }

        int total_time = 0;

        while(!ticket_counter.empty()) {

            int idx = ticket_counter.front().first;
            int tkt = ticket_counter.front().second;

            ticket_counter.pop();

            if(idx == k && tkt == 1) {
                return total_time + 1;
            }

            if(tkt > 1) {
                ticket_counter.push({idx, tkt - 1});
            }

            total_time++;
        }
        
        return total_time;
    }
};