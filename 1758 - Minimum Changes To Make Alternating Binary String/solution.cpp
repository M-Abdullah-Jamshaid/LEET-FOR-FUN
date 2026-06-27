class Solution
{
public:
    int minOperations(string s)
    {
        int count1 = 0;
        int count0 = 0;
        int size = s.size();

        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                {
                    count1++;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    count0++;
                }
            }
        }
        int res = size - (count0 + count1);
        count0 = 0;
        count1 = 0;
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 1)
            {
                if (s[i] == '0')
                {
                    count1++;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    count0++;
                }
            }
        }
        int res2 = size - (count0 + count1);

        return min(res, res2);
    }
};