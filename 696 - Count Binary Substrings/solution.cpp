class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int total = 0;
        int prev_group = 0;
        int curr_group = 1;

        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
            {
              
                curr_group++;
            }
            else
            {
               
                total += min(prev_group, curr_group);

                
                prev_group = curr_group;
                curr_group = 1;
            }
        }

 
        return total + min(prev_group, curr_group);
    }
};