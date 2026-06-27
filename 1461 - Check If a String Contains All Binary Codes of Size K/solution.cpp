class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> m;
        int n = s.length();
        for(int i=0;i<n-k+1;i++){
            m[s.substr(i,k)]++;
            if(m.size()==pow(2,k)){
                return true;
            }
        }
        return (m.size()==pow(2,k));

    }
};