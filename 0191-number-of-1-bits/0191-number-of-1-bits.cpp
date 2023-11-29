class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
     
        while(n != 0)
        {
            if(1 & n)
            {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};