class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if(colors[i]==colors[i+1]){
                
                total=total+min(neededTime[i],neededTime[i+1]);
                if(neededTime[i]>neededTime[i+1]){  int temp=neededTime[i];
                neededTime[i]=neededTime[i+1];
                neededTime[i+1]=temp;}
              
                
            }
        }
        return total;
        
    }
};