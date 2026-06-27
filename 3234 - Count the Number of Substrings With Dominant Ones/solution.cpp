class Solution {
public:
    int getOnes(int l, int r,vector<int>& ones_prefix) {
            if (l > r) return 0;
            return ones_prefix[r + 1] - ones_prefix[l];
        };
    int numberOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> zero;
        vector<int> ones_prefix(n+1,0); 
        
        for (int i =0; i< n; i++) {
            ones_prefix[i+1] = ones_prefix[i]+(s[i]=='1');
            
            if (s[i] == '0') {
                zero.push_back(i);
            }
        }
        
        zero.push_back(n);
        long long res = 0;
        int sid = 0; 

        for (int left =0;left<n;left++) {
            if (s[left]== '1') {
                res += (zero[sid] - left);
            }
            for (int id =sid;id<zero.size()-1; id++) {
                long long cnt0 = id- sid+ 1; 
                if (cnt0 *cnt0>n) {
                    break;
                }

                int p = zero[id];
                int q = zero[id + 1]; 
                int cnt1 = getOnes(left, p,ones_prefix);
                
                long long needed = cnt0*cnt0;
                if (cnt1>= needed) {
                    res+=(q- p);
                } else {
                    long long missingOnes=needed- cnt1;
                    res += max((long long)0, (long long)q-p -missingOnes);
                }
            }
            if (s[left]=='0') {
                sid++;
            }
        }
        return res;
    }
};