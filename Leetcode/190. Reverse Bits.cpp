class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i=0; i<32; i++) {
            int b = (n >> i) & 1;
            res = res | (b << (31-i));
        }
        return res;
    }
};
