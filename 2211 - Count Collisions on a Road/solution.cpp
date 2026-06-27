class Solution {
public:
    int countCollisions(string directions) {
        int start = 0,end = directions.size()-1,c=0,n=directions.size();
        while(start<n && directions[start]=='L'){
            start++;
        }
        while(end>=0 && directions[end]=='R'){
            end--;
        }
        for(int i=start;i<=end;i++){
            if(directions[i]=='S'){
                continue;
            }else{
                c++;
            }
        }return c;
    }
};