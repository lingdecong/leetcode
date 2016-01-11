#include <iostream>
#include "PalindromeNumber.hpp"

using namespace std;

int main() {
    //cout << "Hello, World!" << endl;
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(100) << endl;
    cout << s.isPalindrome(-111) << endl;
    return 0;
}