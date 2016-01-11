//
// Created by jamesdcl on 1/11/16.
//


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        int raw = x;
        int reverse = 0;
        int remain = 0;
        while(x != 0) {
            remain = x % 10;
            reverse = reverse * 10 + remain;
            x /= 10;
        }

        if (reverse == raw)
            return true;
        else
            return false;
    }
};