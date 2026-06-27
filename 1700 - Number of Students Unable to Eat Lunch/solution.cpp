class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> map;
        for(int x:students){
            map[x]++;

        }

        stack<int>s;
        int size=sandwiches.size();
        for(int x=size-1;x>=0;x--){
            s.push(sandwiches[x]);
        }
        while(!s.empty()&& map[s.top()]>0){
            map[s.top()]--;
            s.pop();
        }
        return map[0]+map[1];
    }
};