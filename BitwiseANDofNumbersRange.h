int rangeBitwiseAnd(int m, int n) {
    int mod, bit;
    for (bit = 0, mod = m ^ n; mod != 0; ++bit) {
        mod >>= 1;
    }
    mod = 0xFFFFFFFF - ((1 << bit) - 1);
    return mod & m;
}
