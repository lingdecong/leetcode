class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bit_witch = 31;
        uint32_t sum = 0;
        for (;n > 0; --bit_witch)
        {
            sum += (n & 0x01) * pow(2, bit_witch); 
            n = n >> 1;
        }
        return sum;
    }
};
