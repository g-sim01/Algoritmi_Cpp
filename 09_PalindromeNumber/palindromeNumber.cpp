#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0)) return false;
        int revertedNumber = 0;
        while(x>revertedNumber) {
            revertedNumber = revertedNumber * 10 + x%10;
            x /= 10;
        }
        return x==revertedNumber || x == revertedNumber/10;
    };
};

int main() {
    Solution sol;
    
    cout << boolalpha; 
    
    int test1 = 121;
    cout << "Input: " << test1 << "\nResult: " << sol.isPalindrome(test1) << " | Expected: true\n" << endl;

    int test2 = -121;
    cout << "Input: " << test2 << "\nResult: " << sol.isPalindrome(test2) << " | Expected: false\n" << endl;

    int test3 = 10;
    cout << "Input: " << test3 << "\nResult: " << sol.isPalindrome(test3) << " | Expected: false\n" << endl;

    int test4 = 0;
    cout << "Input: " << test4 << "\nResult: " << sol.isPalindrome(test4) << " | Expected: true\n" << endl;

    int test5 = 1221;
    cout << "Input: " << test5 << "\nResult: " << sol.isPalindrome(test5) << " | Expected: true\n" << endl;

    int test6 = 12321;
    cout << "Input: " << test6 << "\nResult: " << sol.isPalindrome(test6) << " | Expected: true\n" << endl;

    int test7 = 2147447412;
    cout << "Input: " << test7 << "\nResult: " << sol.isPalindrome(test7) << " | Expected: true\n" << endl;

    return 0;
}