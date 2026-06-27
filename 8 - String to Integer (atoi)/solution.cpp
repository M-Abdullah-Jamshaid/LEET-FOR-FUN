class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        int i=0;
        bool sign = true;
        long long ans=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign = false;
            i++;
        }else if(s[i]=='+'){
            sign = true;
            i++;
        }
        int start = i;
        while(s[i]>='0' && s[i]<='9'){
            i++;
        }
        int end=i;
        for(int k=start;k<end;k++){
            if((ans*10+s[k]-'0')>INT_MAX){
                if(sign) return INT_MAX;
                else return INT_MIN;
            }
            ans=ans*10+s[k]-'0';
        }
        if(sign)
        {
            if(ans>INT_MAX)return INT_MAX;
            return ans;
        }
        else{
            if(ans>INT_MAX)return INT_MIN;
            return ans*-1;
        }
    }
    
};