#include <iostream>

using namespace std;

class Solution {
public:
    
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

int main() {
    // Try tests given by LeetCode
    Solution sol;
    cout << boolalpha;
    
    int test1 = 16;
    cout << "Input: " << test1 << "\nOutput: " << sol.isPowerOfFour(test1) << " | Atteso: true\n" << endl;

    int test2 = 5;
    cout << "Input: " << test2 << "\nOutput: " << sol.isPowerOfFour(test2) << " | Atteso: false\n" << endl;

    int test3 = 1;
    cout << "Input: " << test3 << "\nOutput: " << sol.isPowerOfFour(test3)<< " | Atteso: true\n" << endl;

    int test4 = 8;
    cout << "Input: " << test4 << "\nOutput: " << sol.isPowerOfFour(test4) << " | Atteso: false\n" << endl;

    int test5 = 0;
    cout << "Input: " << test5 << "\nOutput: " << sol.isPowerOfFour(test5) << " | Atteso: false\n" << endl;

    int test6 = -16;
    cout << "Input: " << test6 << "\nOutput: " << sol.isPowerOfFour(test6) << " | Atteso: false\n" << endl;

    return 0;
}