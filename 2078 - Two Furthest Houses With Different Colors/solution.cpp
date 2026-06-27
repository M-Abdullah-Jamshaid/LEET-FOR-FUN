class Solution {
public:
    int maxDistance(vector<int>& colors) {
      int size=colors.size();
      int start=0;
      int end=size-1;
      int first=0;
      int sec=0;
      while(start<end){
        if(colors[start]!=colors[end]){
            first= abs(start-end);
            break;
        }

        // if(colors[start+1]!=colors[end]){
        //     first= abs(start+1-end);
        // }
        // if(colors[start]!=colors[end-1]){
        //     first= abs(start-1-end);
        // }
        start++;
      

      }
      start =0,end = size-1;
      while(start<end){
        if(colors[start]!=colors[end]){
            sec= abs(start-end);
            break;
        }

        // if(colors[start+1]!=colors[end]){
        //     return abs(start+1-end);
        // }
        // if(colors[start]!=colors[end-1]){
        //     return abs(start-1-end);
        // }
      
        end--;

      }

      return (first>sec?first:sec);

    } 
};