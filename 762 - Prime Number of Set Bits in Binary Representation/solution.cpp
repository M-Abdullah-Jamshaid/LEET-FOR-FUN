class Solution
{
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        int count = 0;

        for (int i = left; i <= right; i++)
        {
            int bitsbcount = 0;
            int temp=i;
            while (temp != 0)
            {
                // cout << i << endl;
                if ((temp & 1) == 1)
                {
                    bitsbcount++;
                }
                temp = temp >> 1;
            }
            if (isPrime(bitsbcount))
            {
                count++;
            }
        }
        return count;
    }
};