class Solution {
public:
    int reverse(int x) {
        int sign = 0, sum = 0;
        int base = 10;
        if (x < 0) 
        {
            sign = 1;
            base = -10;
        }
        
        vector<int> num;
        
        while (x != 0)
        {
            num.push_back(x % base);
            if (sign == 1)
            {
                x = 0 - x / base;
            }
            else
            {
                x = x / base;
            }
        }
        
        int len = num.size();
        for (int ii = len - 1; ii >= 0; --ii)
        {
            if (sign == 1) 
            {
                // handle overflow
                if (INT_MIN - sum <= num[ii] * pow(10, len - 1 - ii))
                    sum += num[ii] * pow(10, len - 1 - ii);
                else
                    return 0;
            }
            else
            {
                // handle overflow
                if (INT_MAX - sum >= num[ii] * pow(10, len - 1 - ii))
                    sum += num[ii] * pow(10, len - 1 - ii);
                else
                    return 0;
            }
        }
        return sum;
    }
};
