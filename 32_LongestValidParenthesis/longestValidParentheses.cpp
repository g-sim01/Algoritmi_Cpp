#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        
        int left = 0;
        int right = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++right;
            } else {
                ++left;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return max_len;
    }
};

int main() {
    // Try tests given by LeetCode
    Solution sol;
    
    string test1 = "()()";
    cout << "Input:  \"" << test1 << "\"\nResult: " << sol.longestValidParentheses(test1) << " | Expected: 4\n" << endl;

    string test2 = ")()())";
    cout << "Input:  \"" << test2 << "\"\nResult: " << sol.longestValidParentheses(test2) << " | Expected: 4\n" << endl;

    string test3 = "";
    cout << "Input:  \"" << test3 << "\"\nResult: " << sol.longestValidParentheses(test3) << " | Expected: 0\n" << endl;

    string test4 = "(()";
    cout << "Input:  \"" << test4 << "\"\nResult: " << sol.longestValidParentheses(test4) << " | Expected: 2\n" << endl;

    return 0;
}