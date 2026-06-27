class Solution {
public:
    bool isPalindrome(int x) {
     if(x<0)
     return false; 
     long long temp=x;
   long long  num=0;  
     while(temp>0){
     num=(num*10)+(temp%10);
     temp/=10;
     } 
     cout<<num<<endl; 
       return (num==x);
    }
  
};